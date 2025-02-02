echo "--O0"
clang++ -O0 -std=c++14 -Wno-everything -o optimized optimized.cpp
clang++ -O0 -std=c++14 -Wno-everything -o unoptimized unoptimized.cpp
g++ -O0 -std=c++14 -Wno-everything -o optimizedg optimized.cpp
g++ -O0 -std=c++14 -Wno-everything -o unoptimizedg unoptimized.cpp

echo "----clang:"
echo -n "------Optimized:   "
./optimized 7575
cp trash.txt checktrash.txt
echo -e "------Reference"
echo -n "------Unoptimized: "
./unoptimized 7575
if cmp -s trash.txt checktrash.txt; then
    echo -e "------No difference"
else
    echo -e "------Difference"
fi

echo "----gcc:"
echo -n "------Optimized:   "
./optimizedg 7575
if cmp -s trash.txt checktrash.txt; then
    echo -e "------No difference"
else
    echo -e "------Difference"
fi
echo -n "------Unoptimized: "
./unoptimizedg 7575
if cmp -s trash.txt checktrash.txt; then
    echo -e "------No difference"
else
    echo -e "------Difference"
fi

echo "--O2"
clang++ -O2 -std=c++14 -Wno-everything -o optimized optimized.cpp
clang++ -O2 -std=c++14 -Wno-everything -o unoptimized unoptimized.cpp
g++ -O2 -std=c++14 -Wno-everything -o optimizedg optimized.cpp
g++ -O2 -std=c++14 -Wno-everything -o unoptimizedg unoptimized.cpp

echo "----clang:"
echo -n "------Optimized:   "
./optimized 7575
if cmp -s trash.txt checktrash.txt; then
    echo -e "------No difference"
else
    echo -e "------Difference"
fi
echo -n "------Unoptimized: "
./unoptimized 7575
if cmp -s trash.txt checktrash.txt; then
    echo -e "------No difference"
else
    echo -e "------Difference"
fi

echo "----gcc:"
echo -n "------Optimized:   "
./optimizedg 7575
if cmp -s trash.txt checktrash.txt; then
    echo -e "------No difference"
else
    echo -e "------Difference"
fi
echo -n "------Unoptimized: "
./unoptimizedg 7575
if cmp -s trash.txt checktrash.txt; then
    echo -e "------No difference"
else
    echo -e "------Difference"
fi