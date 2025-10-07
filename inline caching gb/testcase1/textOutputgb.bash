BENCHMARK_PREFIX="../../benchmark"
INCLUDE_PATH="-I${BENCHMARK_PREFIX}/include"
LIB_PATH="-L${BENCHMARK_PREFIX}/build/src"

export BENCHMARK_DISABLE_DEPRECATED_WARNING=1
#export BENCHMARK_COLOR=0

echo "--O0 (Google Benchmark)"
clang++ -O0 -std=c++17 ${INCLUDE_PATH} ${LIB_PATH} -o gb_optimized gb_optimized.cpp -lbenchmark -lpthread 2>/dev/null
clang++ -O0 -std=c++17 ${INCLUDE_PATH} ${LIB_PATH} -o gb_unoptimized gb_unoptimized.cpp -lbenchmark -lpthread 2>/dev/null
g++ -O0 -std=c++17 ${INCLUDE_PATH} ${LIB_PATH} -o gb_optimizedg gb_optimized.cpp -lbenchmark -lpthread 2>/dev/null
g++ -O0 -std=c++17 ${INCLUDE_PATH} ${LIB_PATH} -o gb_unoptimizedg gb_unoptimized.cpp -lbenchmark -lpthread 2>/dev/null

echo "----clang:"
echo "------Optimized:"
./gb_optimized 7575 2>/dev/null
cp trash.txt checktrash.txt
echo "------Reference"
echo "------Unoptimized:"
./gb_unoptimized 7575 2>/dev/null
if cmp -s trash.txt checktrash.txt; then
    echo "------No difference"
else
    echo "------Difference"
fi

echo "----gcc:"
echo "------Optimized:"
./gb_optimizedg 7575 2>/dev/null
if cmp -s trash.txt checktrash.txt; then
    echo "------No difference"
else
    echo "------Difference"
fi
echo "------Unoptimized:"
./gb_unoptimizedg 7575 2>/dev/null
if cmp -s trash.txt checktrash.txt; then
    echo "------No difference"
else
    echo "------Difference"
fi

echo "--O2 (Google Benchmark)"
clang++ -O2 -std=c++17 ${INCLUDE_PATH} ${LIB_PATH} -o gb_optimized gb_optimized.cpp -lbenchmark -lpthread 2>/dev/null
clang++ -O2 -std=c++17 ${INCLUDE_PATH} ${LIB_PATH} -o gb_unoptimized gb_unoptimized.cpp -lbenchmark -lpthread 2>/dev/null
g++ -O2 -std=c++17 ${INCLUDE_PATH} ${LIB_PATH} -o gb_optimizedg gb_optimized.cpp -lbenchmark -lpthread 2>/dev/null
g++ -O2 -std=c++17 ${INCLUDE_PATH} ${LIB_PATH} -o gb_unoptimizedg gb_unoptimized.cpp -lbenchmark -lpthread 2>/dev/null

echo "----clang:"
echo "------Optimized:"
./gb_optimized 7575 2>/dev/null
if cmp -s trash.txt checktrash.txt; then
    echo "------No difference"
else
    echo "------Difference"
fi
echo "------Unoptimized:"
./gb_unoptimized 7575 2>/dev/null
if cmp -s trash.txt checktrash.txt; then
    echo "------No difference"
else
    echo "------Difference"
fi

echo "----gcc:"
echo "------Optimized:"
./gb_optimizedg 7575 2>/dev/null
if cmp -s trash.txt checktrash.txt; then
    echo "------No difference"
else
    echo "------Difference"
fi
echo "------Unoptimized:"
./gb_unoptimizedg 7575 2>/dev/null
if cmp -s trash.txt checktrash.txt; then
    echo "------No difference"
else
    echo "------Difference"
fi