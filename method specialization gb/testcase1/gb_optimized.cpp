#include <benchmark/benchmark.h>
#include <iostream>
#include <fstream>

using namespace std;

int _t = 7575;

static long long waste(int n) {
    long long x;
    int t=1e2;
    while(t-->0) {
        x+=n*t;
    }
    x=6776678*n;
    return x;
}

static long long solution(long long n) {
    long long x;
    x=6776678*n;
    return x;
}

class Test {
public:
    static void runTest(benchmark::State& state) {
        for (auto _ : state) {
            int n = _t;
            int t = 1e7;
            long long x = 0;
            while(t-- > 0) {
                x += solution(x) + n;
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