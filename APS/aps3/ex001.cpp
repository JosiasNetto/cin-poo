#include <iostream>
#include <string>

using namespace std;

int main(){

    string s1 = "As time by ...";
    string s2 = "goes";

    s1.insert(11, s2);
    cout << s1 << endl;

    s1.erase(10, 8);
    cout << s1 << endl;

    s1.replace(3, 4, "Bill");
    cout << s1 << endl;

    return 0;
}