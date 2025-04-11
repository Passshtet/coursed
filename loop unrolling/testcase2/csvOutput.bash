clang++ -O0 -std=c++14 -Wno-everything -o optimized optimized.cpp
clang++ -O0 -std=c++14 -Wno-everything -o unoptimized unoptimized.cpp
g++ -O0 -std=c++14 -Wno-everything -o optimizedg optimized.cpp
g++ -O0 -std=c++14 -Wno-everything -o unoptimizedg unoptimized.cpp

./optimized 7575
./unoptimized 7575
./optimizedg 7575
./unoptimizedg 7575

clang++ -O2 -std=c++14 -Wno-everything -o optimized optimized.cpp
clang++ -O2 -std=c++14 -Wno-everything -o unoptimized unoptimized.cpp
g++ -O2 -std=c++14 -Wno-everything -o optimizedg optimized.cpp
g++ -O2 -std=c++14 -Wno-everything -o unoptimizedg unoptimized.cpp

./optimized 7575
./unoptimized 7575
./optimizedg 7575
./unoptimizedg 7575