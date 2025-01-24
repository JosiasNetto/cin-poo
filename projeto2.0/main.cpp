#include <iostream>
#include <string>
#include "parser.h"
#include "expressions.h"

using namespace std;

int main(){
    string readExp;

    cout << "Please enter a expression: \n";
    getline(cin, readExp);
    cout << "Leu a exp \n";

    Parser test = Parser(readExp);
    cout << "Criou o test \n";

    test.nextToken();
    cout << "Foi para o primeiro token \n";

    Expression* parsedExp = test.parser_exp();
    cout << "O valor é: "<<parsedExp->eval() << endl;

    return 0;
}