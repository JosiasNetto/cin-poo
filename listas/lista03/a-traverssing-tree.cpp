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
};

class BST{
    private: 
        BSTNode* root;
        int nodeCount;
    public:
        BST() { root = NULL; nodeCount = 0;}
        // int find_help(BSTNode* rt, int a_key){
        //     if(rt == NULL){
        //         return ;
        //     }else if( rt->get_key() > a_key){
        //         return find_help(rt->get_left(), a_key);
        //     }else if( rt->get_key() < a_key){
        //         return find_help(rt->get_right(), a_key);
        //     }else{
        //         return rt->get_key();
        //     }
        // }
        // int find(int a_key){
        //     return find_help(root, a_key);
        // }
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
        void pre_order(BSTNode* rt){
            if(rt != NULL){
                cout << " " << rt->get_key();
                pre_order(rt->get_left());
                pre_order(rt->get_right());
            }
        }
        void in_order(BSTNode* rt){
            if(rt != NULL){
                in_order(rt->get_left());
                cout << " " << rt->get_key();
                in_order(rt->get_right());
            }
        }
        void post_order(BSTNode* rt){
            if(rt != NULL){
                post_order(rt->get_left());
                post_order(rt->get_right());
                cout << " " << rt->get_key();
            }
        }
        BSTNode* get_root() { return root;}
};

int main(){
    BST tree = BST();
    int numbers;
    cin >> numbers;
    for(int i = 0; i < numbers; i++){
        int num;
        cin >> num;
        tree.insert(num);
    }

    cout << "Pre order :";
    tree.pre_order(tree.get_root());
    cout << endl;
    cout << "In order  :";
    tree.in_order(tree.get_root());
    cout << endl;
    cout << "Post order:";
    tree.post_order(tree.get_root());

    return 0;
}