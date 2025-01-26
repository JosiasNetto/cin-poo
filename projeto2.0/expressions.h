#ifndef _EXPRESSIONS_
#define _EXPRESSIONS_

#include <iostream>
#include <string>

using namespace std;

class Expression {
    protected:
        int value;
        string type;
    public:
        Expression(const string& type) : type(type) {};
        virtual int eval() = 0;
        virtual ~Expression() = default;
        virtual string getType() = 0;
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
    public:
        int eval();
        string getType();
        LiteralExp(int value, const string& type) : literalValue(value), Expression(type) {};
};

class UnaryExp : public Expression {
    private:
        Expression* exp;
        bool operand;
    public:
        int eval();
        string getType();
        UnaryExp(bool op, Expression* exp, const string& type) : operand(op), exp(exp), Expression(type) {};
};

class BinaryExp : public Expression {
    private:
        Expression* exp1;
        Expression* exp2;
        Operand op;
    public:
        int eval();
        string getType();
        BinaryExp(Expression* exp1, Operand op, Expression* exp2, const string& type) : exp1(exp1), op(op), exp2(exp2), Expression(type) {};
};

#endif