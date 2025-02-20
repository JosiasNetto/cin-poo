#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Node {
    private:
        string name;
        Node* next;
    public:
        Node() { this->name = ""; this->next = NULL; }
        Node(string a_name, Node* a_next) { this->name = a_name; this->next = a_next; }
    friend class Queue;
};

class Queue {
    private:
        Node *front, *rear, *curr;
        int size, currNum;
    public:
        Queue() { 
            this->front = this->rear = this->curr = new Node(); 
            this->size = this->currNum = 0; 
        }

        ~Queue() { // Libera a memória alocada
            while (front != nullptr) {
                Node* temp = front;
                front = front->next;
                delete temp;
            }
        }

        void enqueue(string nm) {
            this->rear->next = new Node(nm, NULL);
            this->rear = this->rear->next;
            this->size++;
        }

        void enqueueCurr(string name) {
            if (curr == nullptr) return; // Evita acessar um ponteiro inválido
            Node* temp = this->curr->next;
            this->curr->next = new Node(name, temp);
            this->size++;
        }

        string dequeue() {
            if (this->size == 0 || this->front->next == nullptr) {
                throw "error"; // Evita acessar um ponteiro inválido
            }
            Node* temp = this->front->next;
            string it = temp->name;
            this->front->next = temp->next;
            this->size--;

            if (this->front->next == NULL) {
                this->rear = this->front;
            }

            delete temp;
            return it;
        }

        int getSize() { return this->size; }

        void printQueue() {
            if (this->size == 0) {
                cout << "---" << endl;
                return;
            }

            Node* temp = this->front->next;
            while (temp != NULL) {
                cout << temp->name;
                if (temp->next != NULL) {
                    cout << ", ";
                }
                temp = temp->next;
            }
            cout << endl;
        }

        void moveCurrNext(int n) {
            while (currNum < n - 1 && curr->next != nullptr) {
                curr = curr->next;
                currNum++;
            }
        }

        void moveCurr(int n) {
            curr = front;
            currNum = 0;
            while (currNum < n - 1 && curr->next != nullptr) {
                curr = curr->next;
                currNum++;
            }
        }

        int getCurr() {
            return this->currNum;
        }
};

int main() {
    int c;
    cin >> c;
    cin.ignore();

    for (int i = 0; i < c; i++) {
        cout << "caso " << i + 1 << ":" << endl;
        int n;
        cin >> n;
        cin.ignore();
        Queue q;
        for (int j = 0; j < n; j++) {
            string inp;
            getline(cin, inp);
            istringstream iss(inp);
            string token;
            string op;
            int pos = 0;
            string name;

            while (iss >> token) {
                if (token == "add" || token == "next" || token == "status") {
                    op = token;
                } else if (isdigit(token[0])) { // Verifica se é número antes de converter
                    pos = stoi(token);
                } else {
                    name = token;
                }
            }

            if (op == "add") {
                if (pos == 0) {
                    q.enqueue(name);
                } else {
                    if(pos <= q.getSize()){
                    if (pos > q.getCurr()) {
                        q.moveCurrNext(pos);
                        q.enqueueCurr(name);
                    } else {
                        q.moveCurr(pos);
                        q.enqueueCurr(name);
                    }
                    }
                }
            } else if (op == "next") {
                try {
                    q.dequeue();
                } catch (const char* msg) {
                    cout << msg << endl;
                }
            } else if (op == "status") {
                q.printQueue();
            }
        }
    }
    return 0;
}
