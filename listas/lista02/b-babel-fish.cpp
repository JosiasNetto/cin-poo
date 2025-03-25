#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        string key;
        string element;
        Node(string a_key, string a_element) : key(a_key), element(a_element) {};
        Node() : key(""), element("") {};
};

class OpenHashTable{
    private:
        vector<list<Node>> table;
        int numElements;
    public:
        OpenHashTable() : table(100001), numElements(0) {};
        int hashing(string key) {
            int prime = 31;
            int hash = 0;
            for (int i = 0; i < key.length(); i++) {
                hash = (hash * prime + key[i]) % 100001;
            }
            return hash;
        }
        string findElementSring(string key){
            int index = hashing(key);
            for(auto it = table.at(index).begin(); it != table.at(index).end(); it++){
                if(it->key == key){
                    return it->element;
                }
            }
            return "eh";
        }
        void addElement(string key, string element){
            int index = hashing(key);
            Node node = Node(key, element);
            table.at(index).emplace_back(node);
            numElements++;
            index++;
        }
};

int main(){
    OpenHashTable table = OpenHashTable();
    string line;

    while(getline(cin, line)){
        if (line.empty()) {
            break;
        }
        int space = line.find(' ');
        string key = line.substr(0, space);
        string element = line.substr(space + 1);
        table.addElement(element, key);
    }

    while (getline(cin, line)) {
        cout << table.findElementSring(line) << endl;
    }
    return 0;
}