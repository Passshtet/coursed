#include <iostream>
#include <sstream>
#include <string>
#include <random>
#include <fstream>

int main() {
    std::ostringstream expression;
    int numTerms = 1e4; // Number of terms in the expression
    std::string symb ="+-*/%";

    for (int i = 1; i <= numTerms; ++i) {
        expression <<"x"<<symb[i%5]<<"=";
        expression << std::rand() % 1000000;
        expression << ";\n";
    }

    std::ofstream outfile("expr.txt");
    outfile << expression.str();
    outfile.close(); 
    return 0;
}