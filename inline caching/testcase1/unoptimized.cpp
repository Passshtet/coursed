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

static long long solution(int n) {
    long long x;
    int c=waste(waste(waste(waste(n*n)*n)*n)*n);
    x=6776678*n+c;
    return x;
}

int main(int argc, char* argv[]) {
    int n=*argv[1];
    auto start = chrono::high_resolution_clock::now();
    int t=1e7;
    long long x=0;
    while(t-->0) {
        x+=solution(n);
        if(x%t<t/2)//prohibit loop optimization
        --t;
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    ofstream outfile("trash.txt");
    outfile << x;
    outfile.close();
    return 0;
}