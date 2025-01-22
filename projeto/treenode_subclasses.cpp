#include "treenode_subclasses.h"
#include <iostream>
using namespace std;

TreeNodeRoot::TreeNodeRoot(const string& expression) : TreeNode(expression) {}

Add::Add(const string& expression) : TreeNode(expression) {}
int Add::eval() {return this->right->eval() + this->left->eval();}


Sub::Sub(const string& expression) : TreeNode(expression) {}
int Sub::eval() {return this->right->eval() - this->left->eval();}


Mult::Mult(const string& expression) : TreeNode(expression) {}
int Mult::eval() {return this->right->eval() * this->left->eval();}


Div::Div(const string& expression) : TreeNode(expression) {}
int Div::eval() {return this->right->eval() * this->left->eval();}


Neg::Neg(const string& expression) : TreeNode(expression) {};
int Neg::eval() {return 0 - this->argument->eval();}

Integer::Integer(const string& expression) : TreeNode(expression) {}
int Integer::eval() {this->value = stoi(this->exp); return this->value;}