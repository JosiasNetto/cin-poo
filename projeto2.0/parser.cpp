#include <iostream>
#include <string>
#include "parser.h"
#include "expressions.h"

using namespace std;

void Parser::nextToken() {  
    int auxIndex = this->currentToken.getIndex();
    while (auxIndex < this->stringExp.length() && this->stringExp[auxIndex] == ' ') {
        auxIndex++;
    }
    if(auxIndex < this->stringExp.length()) {
        string nextToken;
        while(auxIndex < this->stringExp.size() && this->stringExp[auxIndex] != ' '){
            nextToken.append(1, this->stringExp[auxIndex]);
            auxIndex++;
        }
        Token readyNextToken = Token( nextToken, auxIndex);
        this->currentToken = readyNextToken;
    }
}

string Token::getValue() {return this->value;}
int Token::getIndex() {return this->index;}


Expression* Parser::parser_exp() { return parser_or_exp(); }

Expression* Parser::parser_or_exp() { 
    Expression* exp1;
    exp1 = parser_and_exp();

    if(this->currentToken.getValue() == "||") {
        Operand op = Operand(this->currentToken.getValue());
        nextToken();
        Expression* exp2;
        exp2 = parser_and_exp();
        return new BinaryExp(exp1, op, exp2, "bool");
    } else {
        return exp1;
    }
}

Expression* Parser::parser_and_exp() { 
    Expression* exp1;
    exp1 = parser_eq_exp();

    if(this->currentToken.getValue() == "&&") {
        Operand op = Operand(this->currentToken.getValue());
        nextToken();
        Expression* exp2;
        exp2 = parser_eq_exp();
        return new BinaryExp(exp1, op, exp2, "bool");
    } else {
        return exp1;
    }
}

Expression* Parser::parser_eq_exp() { 
    Expression* exp1;
    exp1 = parser_rel_exp();

    if(this->currentToken.getValue() == "==" || 
    this->currentToken.getValue() == "!=") {
        Operand op = Operand(this->currentToken.getValue());
        nextToken();
        Expression* exp2;
        exp2 = parser_rel_exp();
        return new BinaryExp(exp1, op, exp2, "bool");
    } else {
        return exp1;
    }
}

Expression* Parser::parser_rel_exp() { 
    Expression* exp1;
    exp1 = parser_add_exp();

    if(this->currentToken.getValue() == "<" || 
    this->currentToken.getValue() == ">" ||
    this->currentToken.getValue() == "<=" ||
    this->currentToken.getValue() == ">=") {
        Operand op = Operand(this->currentToken.getValue());
        nextToken();
        Expression* exp2;
        exp2 = parser_add_exp();
        return new BinaryExp(exp1, op, exp2, "bool");
    } else {
        return exp1;
    }
}

Expression* Parser::parser_add_exp() { 
    Expression* exp1;
    exp1 = parser_mul_exp();

    if(this->currentToken.getValue() == "+" || 
    this->currentToken.getValue() == "-") {
        Operand op = Operand(this->currentToken.getValue());
        nextToken();
        Expression* exp2;
        exp2 = parser_mul_exp();
        return new BinaryExp(exp1, op, exp2, "number");
    } else {
        return exp1;
    }
}

Expression* Parser::parser_mul_exp() { 
    Expression* exp1;
    exp1 = parser_unary_exp();

    if(this->currentToken.getValue() == "*" || 
    this->currentToken.getValue() == "/") {
        Operand op = Operand(this->currentToken.getValue());
        nextToken();
        Expression* exp2;
        exp2 = parser_unary_exp();
        return new BinaryExp(exp1, op, exp2, "number");
    } else {
        return exp1;
    }
}

Expression* Parser::parser_unary_exp() { 
    if(this->currentToken.getValue() == "-") {
        Operand op = Operand(this->currentToken.getValue());
        nextToken();
        Expression* exp;
        exp = parser_unary_exp();
        return new UnaryExp(true, exp, "number");
    } else {
        return parser_primary_exp();
    }
}

Expression* Parser::parser_primary_exp() { 
    if(this->currentToken.getValue() == "(") {
        nextToken();
        Expression* exp1 = parser_exp();
        if(this->currentToken.getValue() != ")"){
            throw "Expected closing parenthesis";
        }
        nextToken();
        return exp1;
    } else {
        return parser_literal_exp();
    }
}

Expression* Parser::parser_literal_exp() { 
    if(this->currentToken.getValue() == "true"){
        nextToken();
        return new LiteralExp(true, "bool");
    }
    else if(this->currentToken.getValue() == "false"){
        nextToken();
        return new LiteralExp(false, "bool");
    }
    else if(!this->currentToken.getValue().empty() && (isdigit(this->currentToken.getValue()[0]) || 
    (this->currentToken.getValue().size() > 1 && isdigit(this->currentToken.getValue()[1])))){
        int number = stoi(this->currentToken.getValue());
        nextToken();
        return new LiteralExp(number, "number");
    }
    else{
        throw "Invalid literal";
    }
}