#include <iostream>
#include <string>

using namespace std;

int main(){

    cout << "\nType a word: \n";

    string userWord;
    cin >> userWord;

    int cnt = 0;
    bool finish = false, palindro = true;

    while(cnt < userWord.length()/2 && !finish){
        if(userWord[cnt] != userWord[(userWord.length() - 1) - cnt]){
            palindro = false;
            finish = true;
        }
        cnt++;
    }
    if(palindro){
        cout << "\nThe word is a Palindrome \n";
    }
    else{
        cout << "\nThe word is not a Palindrome \n";
    }

    return 0;
}