#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;

static long long waste(int n) {
    long long x;
    int t=1e2;
    while(t-->0) {
        x+=n*t;
    }
    x=6776678*n;
    return x;
}

static long long solution(long long n) {
    long long x;
    x=6776678*n;
    return x;
}

int main(int argc, char* argv[]) {
    int n=*argv[1];
    auto start = chrono::high_resolution_clock::now();
    int t=1e7;
    long long x=0;
    while(t-->0) {
        x+=solution(x)+n;
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    ofstream outfile("trash.txt");
    outfile << x;
    outfile.close();
    return 0;
}