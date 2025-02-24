#include <iostream>
#include <string>

using namespace std;

class Node{
    private:
        int element;
        Node* next;
    public:
        Node() { this->element = 0; this->next = NULL;}
        Node(Node* a_next) { this->next = a_next;}
        Node(int a_element, Node* a_next) : element(a_element), next(a_next) {};
        friend class QueueLinkedList;
};

class QueueLinkedList {
    private:
        Node *front, *rear;
        int size;
    public:
        QueueLinkedList() { this->front = this->rear = new Node(0, NULL); this->size = 0;}
        void enqueue(int it){
            this->rear->next = new Node(it, NULL);
            this->rear = this->rear->next;
            this->size++;
        }
        int dequeue(){
            if(this->size == 0){ return -1;}
            Node *it = this->front->next;
            int elem = it->element;
            this->front->next = this->front->next->next;
            if (this->rear == it) {
                this->rear = this->front;
            }
            delete it;
            this->size--;
            return elem;
        }
        int getSize(){
            return this->size;
        }
        int getIt(){
            if(this->size > 0){
                return this->front->next->element;
            }else{
                return -1;
            }
        }
};

int main(){
    int c;
    cin >> c;
    cin.ignore();

    for(int i = 0; i < c; i++){
        int cnt = 0;
        int l, m;
        cin >> l;
        cin >> m;

        int actLength = l * 100;
        bool leftBool = true;

        QueueLinkedList left = QueueLinkedList();
        QueueLinkedList right = QueueLinkedList();

        for(int j = 0; j < m; j++){
            int size; 
            string side;
            cin >> size;
            cin >> side;


            if(side == "left"){
                left.enqueue(size);
            }else if(side == "right"){
                right.enqueue(size);
            }
        }

        while(right.getSize() > 0 || left.getSize() > 0){
            int auxSize = l * 100;
            if(leftBool){
                while(left.getIt() <= auxSize && left.getSize() > 0){
                        auxSize -= left.getIt();
                        left.dequeue();
                    }
            }else{
                while(right.getIt() <= auxSize && right.getSize() > 0){
                        auxSize -= right.getIt();
                        right.dequeue();
                        }
                    }
                    cnt++;
                    leftBool = !leftBool;
                }
        cout << cnt<< endl;
   }
   return 0;
}