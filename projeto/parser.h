#ifndef _PARSER_
#define _PARSER_

#include <iostream>
#include <string>

#include "token.h"
#include "treenode.h"

using namespace std;

class Parser {
    protected:
        Token currentToken;
        Token nextToken;
    public:
        Parser(const string& expression);
        void scanToken();
        TreeNode parseE();
        TreeNode parseT();
        TreeNode parseF();
};


#endif