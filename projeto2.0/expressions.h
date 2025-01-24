#ifndef _EXPRESSIONS_
#define _EXPRESSIONS_

#include <iostream>
#include <string>

using namespace std;

class Expression {
    protected:
        int value;
    public:
        virtual int eval() = 0;
        virtual ~Expression() = default;

};

class Operand {
    private:
        string value;
    public: 
        string getValue();
        Operand(const string& value) : value(value) {};
};

class LiteralExp : public Expression {
    private:
        int literalValue;
        string type;
    public:
        int eval();
        LiteralExp(int value, const string& type) : literalValue(value), type(type) {};
};

class UnaryExp : public Expression {
    private:
        Expression* exp;
        bool operand;
    public:
        int eval();
        UnaryExp(bool op, Expression* exp) : operand(op), exp(exp) {};
};

class BinaryExp : public Expression {
    private:
        Expression* exp1;
        Expression* exp2;
        Operand op;
    public:
        int eval();
        BinaryExp(Expression* exp1, Operand op, Expression* exp2) : exp1(exp1), op(op), exp2(exp2) {};
};

#endif