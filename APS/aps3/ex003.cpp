#include <iostream>

using namespace std;

long double factorial(unsigned int num){
    if(num == 0){
        return 1;
    }
    else{
        return num * factorial(num - 1);
    }
}

int main(){

    for(int i = 0; i < 21; i++){
        cout << "\nThe factorial of " << i << " is equal to: "<< factorial(i)<< endl;

        long double facLoop = 1;
        for(int j = i; j > 0; j--){
            facLoop *= j;
        }
        cout << "\nThe factorial of " << i << " is equal to: "<< facLoop<< endl;
    }

    return 0;
}