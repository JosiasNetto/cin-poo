#include <bits/stdc++.h>

using namespace std;

class BSTNode{
    private:
        int key;
        BSTNode* left;
        BSTNode* right;
    public:
        BSTNode(int a_key) { key = a_key; left = right = NULL; }
        int get_key() { return key; }
        BSTNode* get_right() { return right; }
        BSTNode* get_left() { return left; }
        void set_left(BSTNode* nd) { left = nd; }
        void set_right(BSTNode* nd) { right = nd; }
        void set_key(int a_key) { key = a_key;}
};

class BST{
    private: 
        BSTNode* root;
        int nodeCount;
    public:
        BST() { root = NULL; nodeCount = 0;}
        int get_node_cnt() { return nodeCount;}
        int find_help(BSTNode* rt, int a_key){
            if(rt == NULL){
                return INT_MAX;
            }else if( rt->get_key() > a_key){
                return find_help(rt->get_left(), a_key);
            }else if( rt->get_key() < a_key){
                return find_help(rt->get_right(), a_key);
            }else{
                return rt->get_key();
            }
        }
        int find(int a_key){
            return find_help(root, a_key);
        }
        BSTNode* get_min(BSTNode* rt){
            if(rt->get_left() == NULL){
                return rt;
            }
            return get_min(rt->get_left());
        }
        BSTNode* delete_min(BSTNode* rt){
            if(rt->get_left() == NULL){
                return rt->get_right();
            }
            rt->set_left(delete_min(rt->get_left()));
            return rt;
        }
        
        BSTNode* remove_help(BSTNode* rt, int a_key){
            if(rt == NULL){
                return NULL;
            }
            if(rt->get_key() > a_key){
                rt->set_left(remove_help(rt->get_left(), a_key));
            }else if(rt->get_key() < a_key){
                rt->set_right(remove_help(rt->get_right(), a_key));
            }else{
                if(rt->get_left() == NULL){
                    return rt->get_right();
                }else if(rt->get_right() == NULL){
                    return rt->get_left();
                }else{
                    BSTNode* temp = get_min(rt->get_right());
                    rt->set_key(temp->get_key());
                    rt->set_right(delete_min(rt->get_right()));
                }
            }
            return rt;
        }
        int remove(int a_key){
            int temp = find_help(root, a_key);
            if(temp != INT_MAX){
                root = remove_help(root, a_key);
                nodeCount--;
            }
            return temp;
        }
        BSTNode* insert_help(BSTNode* rt, int a_key){
            if(rt == NULL){
                return new BSTNode(a_key);
            }else if( rt->get_key() > a_key){
                rt->set_left(insert_help(rt->get_left(), a_key));
            }else{
                rt->set_right(insert_help(rt->get_right(), a_key));
            }
            return rt;
        }
        void insert(int a_key){
            root = insert_help(root, a_key);
            nodeCount++;
        }
        void post_order(BSTNode* rt){
            if(rt != NULL){
                post_order(rt->get_left());
                post_order(rt->get_right());
                cout<< rt->get_key()<< endl;
            }
        }
        BSTNode* get_root() { return root;}
};

int main(){
    BST tree = BST();
    int c;
    cin >> c;
    for(int i = 0; i < c; i++){
        string op;
        int num;
        cin >> op;
        cin >> num;
        if(op == "ins"){
            tree.insert(num);
        }else if(op == "rem"){
            tree.remove(num);
        }
    }
    cout << tree.get_node_cnt()<<endl;
    tree.post_order(tree.get_root());

    return 0;
}