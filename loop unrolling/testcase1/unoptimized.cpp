#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
    int n=*argv[1];
    auto start = chrono::high_resolution_clock::now();
    int t=1e2;
    long long x=0;
    while(t-->0) {
        x+=n*t;
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    ofstream outfile("trash.txt");
    outfile << x;
    outfile.close();
    return 0;
}