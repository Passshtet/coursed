#include <benchmark/benchmark.h>
#include <iostream>
#include <fstream>

using namespace std;

int _t = 7575;

long long solution(int n) {
    long long x;
    x=969824627*n%1000007;
    return x;
}

class Test {
public:
    static void runTest(benchmark::State& state) {
        for (auto _ : state) {
            int t = _t;
            long long x = 0;
            while(t-- > 0) {
                x += solution(t);
            }
            
            ofstream outfile("trash.txt");
            outfile << x;
            outfile.close();
        }
    }
};

static void BM_Test_U(benchmark::State& state) {
    Test::runTest(state);
}

BENCHMARK(BM_Test_U)->Iterations(30);

int main(int argc, char** argv) {
    if (argc > 1) {
        _t = atoi(argv[1]);
    }
    
    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
    return 0;
}