#include <iostream>
#include <string>
#include "expressions.h"

using namespace std;

string Operand::getValue() {return this->value;}

int LiteralExp::eval() {return this->literalValue;}

int UnaryExp::eval() {
    if(this->operand){
        return 0 - this->exp->eval();
    }
    else{
        return this->exp->eval();
    }
}

int BinaryExp::eval() {
    string strOp = this->op.getValue();

    if(strOp == "+"){return this->exp1->eval() + this->exp2->eval();}
    if(strOp == "-"){return this->exp1->eval() - this->exp2->eval();}
    if(strOp == "*"){return this->exp1->eval() * this->exp2->eval();}
    if(strOp == "/"){return this->exp1->eval() / this->exp2->eval();}
    return -666;
}