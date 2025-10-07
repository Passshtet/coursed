#include <benchmark/benchmark.h>
#include <memory>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int _t = 7575;

class OptimizedBuffer {
private:
    int data[50];
    int size;
    
public:
    OptimizedBuffer(int s) : size(s) {
        if (size > 50) size = 50;  
        for (int i = 0; i < size; ++i) {
            data[i] = i * 3 + 17;
        }
    }
    
    long long sum() {
        long long total = 0;
        for (int i = 0; i < size; ++i) {
            total += data[i];
        }
        return total;
    }
};

long long processBuffer() {
    OptimizedBuffer buf(50);
    return buf.sum();
}

class Test {
public:
    static void runTest(benchmark::State& state) {
        for (auto _ : state) {
            int t = _t;
            long long x = 0;
            
            while(t-- > 0) {
                x += processBuffer();
            }
            
            ofstream outfile("trash.txt");
            outfile << x;
            outfile.close();
        }
    }
};

static void BM_Test_O(benchmark::State& state) {
    Test::runTest(state);
}

BENCHMARK(BM_Test_O)->Iterations(30);

int main(int argc, char** argv) {
    if (argc > 1) {
        _t = atoi(argv[1]);
    }
    
    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
    return 0;
}