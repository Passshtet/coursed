#include <benchmark/benchmark.h>
#include <iostream>
#include <fstream>
#include <type_traits>

using namespace std;

int _t = 7575;

template<typename T>
static long long processGenericArray(T* arr, int size) {
    long long sum = 0;
    for(int i = 0; i < size; ++i) {
        if(is_same<T, int>::value) {
            sum += static_cast<long long>(arr[i]) * 42 + 13;
        } else {
            sum += static_cast<long long>(arr[i]) * 41 + 12;
        }
    }
    return sum % 1000003;
}

template<typename T, int SIZE>
static long long processTemplateArray(T* arr) {
    long long sum = 0;
    for(int i = 0; i < SIZE; ++i) {
        sum += static_cast<long long>(arr[i]);
        if(SIZE > 5) sum *= 42;
        sum += 13;
    }
    return sum % 1000003;
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
                
                x += processTemplateArray<int, 10>(arr);
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