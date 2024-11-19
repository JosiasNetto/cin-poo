#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    //A
    /* Left-justify the number 0.123456 in an output field with a width of 15.*/
    float numberA = 0.123456;

    cout.width(15);
    cout << left << fixed << setprecision(6) << numberA << endl;

    //B
    /*
Output the number 23.987 as a fixed point number rounded to two decimal places, right-justifying the output in a field with a width of 12.
*/
    float numberB = 23.987;
    
    cout.width(12);
    cout << right << fixed << setprecision(2) << numberB << endl;

    //C
    /*Output the number –123.456 as an exponential and with four decimal spaces */
    float numberC = -123.456;
    cout.width(10);
    cout << scientific << setprecision(4) << numberC << endl;

    return 0;
}