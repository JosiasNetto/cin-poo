#ifndef _TREENODE_SUBCLASSES
#define _TREENODE_SUBCLASSES

#include <iostream>
#include <string>
#include <treenode.cpp>

using namespace std;

class TreeNodeRoot : public TreeNode {
    protected:
        TreeNode* root;
    public:
        TreeNodeRoot(const string& expression) : TreeNode(expression) {};
};

class Add : public TreeNode {
    protected:
        TreeNode* right;
        TreeNode* left;
    public:
        Add(const string& exp) : TreeNode(exp) {}; 
        ~Add();
        int eval();
};

class Sub : public TreeNode {
    protected:
        TreeNode* right;
        TreeNode* left;
    public:
        Sub(const string& exp) : TreeNode(exp) {}; 
        ~Sub();
        int eval();
};

class Mult : public TreeNode {
    protected:
        TreeNode* right;
        TreeNode* left;
    public:
        Mult(const string& exp) : TreeNode(exp) {}; 
        ~Mult();
        int eval();
};

class Div : public TreeNode {
    protected:
        TreeNode* right;
        TreeNode* left;
    public:
        Div(const string& exp) : TreeNode(exp) {}; 
        ~Div();
        int eval();
};

class Neg : public TreeNode {  
    protected: 
        TreeNode* argument;
    public:
        Neg(const string& exp) : TreeNode(exp) {}; 
        ~Neg();
        int eval();
};

class Integer : public TreeNode {
    protected:
        int value;
    public:
        Integer(const string& expression) : TreeNode(expression) {};
        ~Integer();
        int eval();  
};

#endif