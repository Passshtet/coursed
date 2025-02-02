#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;

int main() {
    auto start = chrono::high_resolution_clock::now();
    long long x=925292;
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    ofstream outfile("trash.txt");
    outfile << x;
    outfile.close();
    return 0;
}