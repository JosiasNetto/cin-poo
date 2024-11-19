#include <iostream>

using namespace std;

int main()
{

unsigned int seed;

cout << "Type a number beetween 0 and 65535" << endl;
cin >> seed;
srand(seed);

for(int i = 0; i < 20; i++){
    cout << rand() % 100 + 1 << endl;
}

return 0;
}