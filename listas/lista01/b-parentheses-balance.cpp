#include <iostream>
#include <string>

using namespace std;

class Node{
    private:
        char element;
        Node* next;
    public:
        Node() { this->element = ' '; this->next = NULL;}
        Node(Node* a_next) { this->next = a_next;}
        Node(char a_element, Node* a_next) : element(a_element), next(a_next) {};
        friend class Stack;
};

class Stack{
    private:
        int size;
        Node* top;
    public:
        Stack(){this->top = new Node(NULL); this->size = 0;}
        void push(char element){
            this->top = new Node(element, this->top);
            this->size++;
        }
        char pop(){
            if(this->top == NULL){ return ' '; }
            Node* it = this->top;
            char itElement = it->element;
            this->top = this->top->next;
            delete it;
            this->size--;
            return itElement;
        }
        int getSize(){ return this->size; }
};

int main(){
    int c;
    cin >> c;
    cin.ignore();

    for(int i = 0; i < c; i++){
        string parent;
        getline(cin, parent);

        bool isCorrect = true;
        Stack firstParent;

        for(int j = 0; j < parent.length(); j++){
            if(parent[j] == '(' || parent[j] == '['){
                firstParent.push(parent[j]);
            }else if(parent[j] == ')'){
                if(firstParent.getSize() == 0 || firstParent.pop() != '('){
                    isCorrect = false;
                }
            }else if(parent[j] == ']'){
                if(firstParent.getSize() == 0 || firstParent.pop() != '['){
                    isCorrect = false;
                }
            }
        }
        if(isCorrect && firstParent.getSize() == 0){
            cout << "Yes"<<endl;
        }else{
            cout << "No"<<endl;
        }
    }

    return 0;
}