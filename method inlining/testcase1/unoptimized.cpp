#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;

long long solution(int n) {
    long long x;
    x=969824627*n%1000007;
    return x;
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    int t=1e9;
    long long x=0;
    while(t-->0) {
        x+=solution(t);
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    //cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    cout << " | " << elapsed.count();//output for csv
    ofstream outfile("trash.txt");
    outfile << x;
    outfile.close();
    return 0;
}