#ifndef _PARSER_
#define _PARSER_

#include <iostream>
#include <string>
#include "expressions.h"
using namespace std;

class Token {
    private:
        string value;
        int index;
    public:
        string getValue();
        int getIndex();
        Token(const string& value, int index) : value(value), index(index) {};
        Token() : value(""), index(-1) {};
};

class Parser {
    private:
        string stringExp;
        Expression* exp;
        Token currentToken;
    public:
        Parser(const string& stringExp) : stringExp(stringExp), currentToken("", 0) {};
        void nextToken();
        Expression* parser_exp();
        Expression* parser_or_exp();
        Expression* parser_and_exp();
        Expression* parser_eq_exp();
        Expression* parser_rel_exp();
        Expression* parser_add_exp();
        Expression* parser_mul_exp();
        Expression* parser_unary_exp();
        Expression* parser_primary_exp();
        Expression* parser_literal_exp();
};

#endif