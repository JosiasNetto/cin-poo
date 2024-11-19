#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {

  char ch;
  string word;

  cout << "Let's go! Press the return key: " << endl;
  cin.get(ch);

  cout << "Enter a word containing three characters at most: ";
  cin >> setw(3) >> word;

  cout << "Your input: " << word << endl;
  return 0;
}
