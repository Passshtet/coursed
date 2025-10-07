#include <benchmark/benchmark.h>
#include <iostream>
#include <fstream>
#include <type_traits>

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

template <typename T>
static long long solution(T n) {
    long long x;
    int c=waste(waste(waste(waste(n*n)*n)*n)*n);
    if(!is_same<T, long long>::value) {
        n+=c;
    }
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