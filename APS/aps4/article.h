#ifndef _ARTICLE_
#define _ARTICLE_

#include <iostream>
#include <string.h>

using namespace std;

class Article{
    private:
        long number;
        string name;
        double price;
    public:
        Article(long, const string&, double);
        ~Article();
        void print();
        void setNumber(long);
        void setPrice(double);
        long getNumber();
        string getName();
        double getPrice();
};

#endif