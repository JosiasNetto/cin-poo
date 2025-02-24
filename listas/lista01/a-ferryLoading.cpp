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
        Node* front, rear;
        int size;
    public:
        QueueLinkedList() { this->front = new Node(NULL);this->rear = new Node(NULL); this->size = 0;}
        void enqueue(int it){
            this->rear.next = new Node(it, NULL);
            this->rear = this->rear.next;
            this->size++;
        }
        Node dequeue(){
            if(this->size == 0){ throw "Error";}
            Node it = this->front->next;
            this->front = this->front->next->next;
            this->size--;
            return it;
        }
        int getSize(){
            return size;
        }
        int getIt(){
            return front->next->element;
        }
};

int main(){
    int c;
    cin >> c;

    for(int i = 0; i < c; i++){
        int l, m;
        double actLength = l;
        cin >> l;
        cin >> m;

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
            int auxSize = l;
            bool auxLimit = false;
            if(leftBool){
                while(!auxLimit){
                    if(left.getIt() > auxSize){
                        auxLimit = true;
                    }else{
                        auxSize = auxSize - left.getIt();
                        left.dequeue();
                    }
                }
            }else{
                while(!auxLimit){
                    if(right.getIt() > auxSize){
                        auxLimit = true;
                    }else{
                        auxSize = auxSize - right.getIt();
                        right.dequeue();
                    }
                }
            }
        }
   }
   return 0;
}