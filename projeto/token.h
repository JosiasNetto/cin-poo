#ifndef _TOKEN_
#define _TOKEN_

#include <iostream>
#include <string>

using namespace std;

class Token {
    protected:
        string value;
        int index;
    public:
        Token(const string& token,int index);
};


#endif