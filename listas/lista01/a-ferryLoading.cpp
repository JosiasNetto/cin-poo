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
};

int main(){
    int c;
    cin >> c;

    for(int i = 0; i < c; i++){
        int l, m;
        double actLength = l;
        cin >> l;
        cin >> m;

        QueueLinkedList left = QueueLinkedList();
        QueueLinkedList right = QueueLinkedList();
        for(int j = 0; j < m; j++){
            int size; 
            string side;
            cin >> size;
            cin >> side;

            double convSize = size/100;
            if(actLength - convSize >= 0){
                
            }
        }
   }
   return 0;
}