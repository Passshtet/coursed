#include <iostream>
#include <sstream>
#include <string>
#include <random>
#include <fstream>

int main() {
    std::ostringstream expression;
    int numTerms = 1e2; // Number of terms in the expression
    std::string symb ="+-*/%";

    for (int i = numTerms-1; i >= 0; --i) {
        expression<<"x+=n*"<<i<<";\n";
    }

    std::ofstream outfile("expr.txt");
    outfile << expression.str();
    outfile.close(); 
    return 0;
}