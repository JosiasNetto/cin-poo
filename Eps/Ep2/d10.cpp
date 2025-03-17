#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int key;
        string element;
        Node(int a_key, string a_element) : key(a_key), element(a_element) {};
};

class OpenHashTable{
    private:
        vector<list<Node>> table;
        int numElements;
    public:
        OpenHashTable() { table.resize(10); numElements = 0;}
        int hashFunction(int key) { return key % 10;}
        void addElement(int key, string element){
            if(findElement(key)){
                return;
            }
            Node node = Node(key, element);
            int hashedKey = hashFunction(key);
            table.at(hashedKey).push_back(node);
            numElements++;
        }
        void deleteElement(int key){
            if(!findElement(key)){
                return;
            }
            int hashedKey = hashFunction(key);
            for(auto it = table[hashedKey].begin(); it!= table[hashedKey].end(); it++){ 
                if(it->key == key){
                    table[hashedKey].erase(it);
                    numElements--;
                    return;
                }
            }
        }
        int getNumElement() { return numElements; }
        void printTable(){
            cout << "alpha = "<< getNumElement()<<"/10"<<endl;
            for(int k = 0; k < 10; k++){
                cout<<k<<":";
                int aux = 0;
                for(auto it = table[k].begin(); it!= table[k].end(); it++){
                    if(aux == 0){
                       cout<< "("<< it->key<< "," << it->element <<")";
                    } else{
                        cout<< ",("<< it->key<< "," << it->element <<")";
                    }
                    aux++;
                }
                cout<<endl;   
        }
        }
        bool findElement(int key){
            int hashedKey = hashFunction(key);
            for(auto it = table[hashedKey].begin(); it!= table[hashedKey].end(); it++){ 
                if(it->key == key){
                    return true;
                }
            }
            
            return false;
        }
};

int main(){
    int c;
    cin >> c;
    for(int i = 0; i < c; i++){
        OpenHashTable table = OpenHashTable();
        int n;
        cin >> n;
        for(int j = 0; j < n; j++){
            string op;
            cin >> op;
            if(op == "add"){
                int num;
                string nome;
                cin >> num;
                cin >> nome;
                table.addElement(num, nome);
            }else if(op == "del"){
                int num;
                cin >> num;
                table.deleteElement(num);
            }
        }
        cout << "caso "<< i + 1<<":"<<endl;
        table.printTable();
    }
    return 0;
}