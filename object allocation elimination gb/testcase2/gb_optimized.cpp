#include <benchmark/benchmark.h>
#include <iostream>
#include <fstream>
#include <memory>

using namespace std;

int _t = 7575; 

class OptimizedContainer {
private:
    double values[30]; 
    int count;
    
public:
    OptimizedContainer(int n) : count(n) {
        if (count > 30) count = 30;  
        for (int i = 0; i < count; ++i) {
            values[i] = i * 2.5 + 10.0;
        }
    }
    
    double calculate() {
        double result = 0.0;
        for (int i = 0; i < count; ++i) {
            result += values[i] * values[i];
        }
        return result / count;
    }
};

double processContainers() {
    OptimizedContainer c1(30);
    OptimizedContainer c2(25);
    
    return c1.calculate() + c2.calculate();
}

class Test {
public:
    static void runTest(benchmark::State& state) {
        for (auto _ : state) {
            int t = _t;
            double x = 0.0;
            
            while(t-- > 0) {
                x += processContainers();
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