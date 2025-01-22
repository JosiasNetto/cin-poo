#ifndef _TREENODE_
#define _TREENODE_

#include <iostream>
#include <string>

using namespace std;

class TreeNode {
    protected:
        string exp;
        int value;
    public:
        TreeNode(const string& exp);
        virtual ~TreeNode();
        virtual int eval();
};

#endif