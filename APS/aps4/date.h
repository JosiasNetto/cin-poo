#ifndef _DATE_
#define _DATE_

#include <iostream>
#include <string>

using namespace std;

class Date  {
    private:
        int day, month, year;
    public:
        void init(int month, int day, int year);
        void init(void);
        void print(void);
};

#endif