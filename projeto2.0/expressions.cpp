#include <iostream>
#include <string>
#include "expressions.h"

using namespace std;

string Operand::getValue() {return this->value;}

int LiteralExp::eval() {return this->literalValue;}

string LiteralExp::getType() {return this->type;}
string UnaryExp::getType() {return this->type;}
string BinaryExp::getType() {return this->type;}

int UnaryExp::eval() {
    if(this->operand && this->getType() == "number"){
        return 0 - this->exp->eval();
    }
    else{
        return this->exp->eval();
    }
}

int BinaryExp::eval() {
    string strOp = this->op.getValue();
    string type1 = this->exp1->getType();
    string type2 = this->exp2->getType();

    if(strOp == "+" && (type1 == "number" && type2 == "number")){return this->exp1->eval() + this->exp2->eval();}
    if(strOp == "-" && (type1 == "number" && type2 == "number")){return this->exp1->eval() - this->exp2->eval();}
    if(strOp == "*" && (type1 == "number" && type2 == "number")){return this->exp1->eval() * this->exp2->eval();}
    if(strOp == "/" && (type1 == "number" && type2 == "number")){if(this->exp2->eval() != 0){this->exp1->eval() / this->exp2->eval();} throw "divide 0"; }
    if(strOp == "||" && (type1 == "bool" && type2 == "bool")){return this->exp1->eval() || this->exp2->eval();}
    if(strOp == "&&" && (type1 == "bool" && type2 == "bool")){return this->exp1->eval() && this->exp2->eval();}
    if(strOp == "<" && (type1 == "number" && type2 == "number")){return this->exp1->eval() < this->exp2->eval();}
    if(strOp == ">" && (type1 == "number" && type2 == "number")){return this->exp1->eval() > this->exp2->eval();}
    if(strOp == "<=" && (type1 == "number" && type2 == "number")){return this->exp1->eval() <= this->exp2->eval();}
    if(strOp == ">=" && (type1 == "number" && type2 == "number")){return this->exp1->eval() >= this->exp2->eval();}
    if(strOp == "==" && (type1 == "bool" && type2 == "bool") || (type1 == "number" && type2 == "number")){return this->exp1->eval() == this->exp2->eval();}
    if(strOp == "!=" && (type1 == "bool" && type2 == "bool") || (type1 == "number" && type2 == "number")){return this->exp1->eval() != this->exp2->eval();}
    throw "Invalid binary operation";
}