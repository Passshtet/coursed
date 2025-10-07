#include <benchmark/benchmark.h>
#include <iostream>
#include <fstream>

using namespace std;

int _t = 7575;

static long long processIntArray(int* arr, int size) {
    long long sum = 0;
    for(int i = 0; i < size; ++i) {
        sum += arr[i] * 42 + 13;
    }
    return sum % 1000003;
}

static long long processArray10(int* arr) {
    return ((long long)(arr[0] + arr[1] + arr[2] + arr[3] + arr[4] + 
                       arr[5] + arr[6] + arr[7] + arr[8] + arr[9]) * 42 + 13) % 1000003;
}

class Test {
public:
    static void runTest(benchmark::State& state) {
        for (auto _ : state) {
            int n = _t;
            int t = n / 100;
            long long x = 0;
            int arr[10];
            
            while(t-- > 0) {
                for(int i = 0; i < 10; ++i) {
                    arr[i] = t + i;
                }
                
                x += processArray10(arr);
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