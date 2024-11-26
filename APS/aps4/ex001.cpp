#include "date.h"
#include <ctime>

void Date::init(int month, int day, int year){
    this->month = month;
    this->day = day;
    this->year = year;
}

void Date::init(void){
    struct tm *ptr;
    time_t sec;
    time(&sec);
    ptr = localtime(&sec);

    this->day = ptr->tm_mday;
    this->month = ptr->tm_mon + 1;
    this->year = ptr->tm_year + 1900;
}

void Date::print(void){
    cout << "The date is: " << this->month << "-" << this->day <<
"-" << this->year << endl;}

int main(){
    Date heitor;
    heitor.init(2, 19, 2006);

    Date bebe;
    bebe.init();

    heitor.print();
    bebe.print();

    return 0;
}
