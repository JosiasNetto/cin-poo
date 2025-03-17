#include <bits/stdc++.h>

using namespace std;

class OpenTable{
    private:
        vector<string> table;
        int numElements;
    public:
        OpenTable() : table(101, ""), numElements(0) {};
        int hashing(string key){
            int sum = 0;
            for(int i = 0; i < key.length(); i++){
                sum = sum + (key[i] * (i + 1));
            }
            sum = sum * 19;
            return sum % 101;
        }

        bool findElement(string key){
            int hashedKey = hashing(key);
            for(int i = 0; i < table.size(); i++){ 
                if(table.at(i) == key){
                    return true;
                }
            }
            return false;
        }
        void insert(string key){
            int index = hashing(key);
            if(findElement(key)){
                return;
            }
            for (int j = 0; j < 20; j++) {
                int pos = (index + j * j + 23 * j) % 101;
                if (table[pos].empty() || table[pos] == "") {
                    table[pos] = key;
                    numElements++;
                    return;
                }
            }
        }
        void delt(string key){
            int index = hashing(key);
            for(int i = 0; i < table.size(); i++){
                if(table.at(i) == key){
                    table[i] = "";
                    numElements--;
                    return;
                }
            }
        }
        int getNumEle() {return numElements;}
        void printTable() {
            for(int i = 0; i < table.size(); i++){
                if(table.at(i) != ""){
                    cout << i <<":"<< table.at(i) <<endl;
                }
            }
        }
};

int main(){

    int cases;
    cin >> cases;

    for(int i = 0; i < cases; i++){
        OpenTable hashTable;
        int numOperations;
        cin >> numOperations;
        for(int j = 0; j < numOperations; j++){
            string op;
            cin >> op;
            string inputKey;
            inputKey = op.substr(4);
            if(op[0] == 'A'){
                hashTable.insert(inputKey);
            }else if(op[0] == 'D'){
                hashTable.delt(inputKey);
            }
        }
        cout << hashTable.getNumEle() << endl;
        hashTable.printTable();
    }

    return 0;
}