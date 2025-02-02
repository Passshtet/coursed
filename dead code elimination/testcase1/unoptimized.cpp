#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;

static long long solution(int n) {
    long long x;
    x=6776678*n;
    return x;
}

int main(int argc, char* argv[]) {
    int n=*argv[1];
    auto start = chrono::high_resolution_clock::now();
    int t=1e9;
    long long x=0;
    while(t-->0) {
        x+=solution(x)+n;
    }
    t=1e3;
    long long y=0;
    while(t-->0) {
        y+=solution(y)+n;
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    ofstream outfile("trash.txt");
    outfile << y;
    outfile.close();
    return 0;
}