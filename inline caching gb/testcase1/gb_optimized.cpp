#include <benchmark/benchmark.h>
#include <iostream>
#include <fstream>

using namespace std;

class Test {
private:
    static long long waste(int n) {
        long long x = 0;
        int t = 1e2;
        while(t-- > 0) {
            x += n * t;
        }
        x = 6776678 * n;
        return x;
    }

    static long long solution(long long n) {
        long long x;
        x = 6776678 * n;
        return x;
    }

public:
    static long long runTest(int n) {
        int t = 1e7;
        long long x = 0;
        int c = waste(waste(waste(waste(n * n) * n) * n) * n);
        
        while(t-- > 0) {
            x += 6776678 * n + c;
            if(x % t < t / 2) 
                --t;
        }
        
        return x;
    }
};

static int _n = 7575;

static void BM_Test_O(benchmark::State& state) {
    int n = _n;
    
    for (auto _ : state) {
        long long result = Test::runTest(n);
        benchmark::DoNotOptimize(result);
        
        ofstream outfile("trash.txt");
        outfile << result;
        outfile.close();
    }
}

BENCHMARK(BM_Test_O)->Iterations(30);

int main(int argc, char* argv[]) {
    if (argc >= 2) {
        _n = atoi(argv[1]);
        for (int i = 1; i < argc - 1; ++i) {
            argv[i] = argv[i + 1];
        }
        argc--;
    }
    
    benchmark::Initialize(&argc, argv);
    if (benchmark::ReportUnrecognizedArguments(argc, argv)) return 1;
    benchmark::RunSpecifiedBenchmarks();
    benchmark::Shutdown();
    return 0;
}