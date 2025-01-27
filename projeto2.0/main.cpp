#include <iostream>
#include <string>
#include "parser.h"
#include "expressions.h"

using namespace std;

int main(){

    int c;
    cin >> c;
    cin.ignore();

    for(int i = 0; i < c; i++){
        try{
        string readExp;
        getline(cin, readExp);

        Parser test = Parser(readExp);
        test.nextToken();

        Expression* parsedExp = test.parser_exp();
        string type = parsedExp->getType();
        int value = parsedExp->eval();

        if(type == "bool"){
            cout << (value == 1 ? "true" : "false") << endl;
        }else{
            cout << value << endl;
        }
        delete parsedExp;
        }catch(...){
            cout << "error" << endl;
        }
    }
    return 0;
}