g++ -O0 -std=c++14 -Wno-everything -o optimizedg optimized.cpp
g++ -O0 -std=c++14 -Wno-everything -o unoptimizedg unoptimized.cpp

./optimizedg 7575
./unoptimizedg 7575

g++ -O2 -std=c++14 -Wno-everything -o optimizedg optimized.cpp
g++ -O2 -std=c++14 -Wno-everything -o unoptimizedg unoptimized.cpp

./optimizedg 7575
./unoptimizedg 7575