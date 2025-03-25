#include <bits/stdc++.h>

using namespace std;

class BSTNode{
    private:
        char key;
        BSTNode* left;
        BSTNode* right;
    public:
        BSTNode(char a_key) { key = a_key; left = right = NULL; }
        char get_key() { return key; }
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
        BSTNode* insert_help(BSTNode* rt, char a_key){
            if(rt == NULL){
                return new BSTNode(a_key);
            }else if( rt->get_key() > a_key){
                rt->set_left(insert_help(rt->get_left(), a_key));
            }else{
                rt->set_right(insert_help(rt->get_right(), a_key));
            }
            return rt;
        }
        void insert(char a_key){
            root = insert_help(root, a_key);
            nodeCount++;
        }
        void pre_order(BSTNode* rt){
            if(rt != NULL){
                cout<< rt->get_key();
                pre_order(rt->get_left());
                pre_order(rt->get_right());
            }
        }
        BSTNode* get_root() { return root;}
};

int main(){
    string leaves;
    cin >> leaves;
    while( leaves != "$"){
        BST tree = BST();
        vector<string> elements;
        if(leaves == "*"){
            cin >> leaves;
        }
        elements.push_back(leaves);
        cin >> leaves;
        while(leaves != "*" && leaves != "$"){
            elements.push_back(leaves);
            cin >> leaves;
        }
        for(int i = elements.size() - 1; i >= 0; i--){
            for(int j = 0; j < elements[i].size(); j++){
                tree.insert(elements[i][j]);
            }
        }
        tree.pre_order(tree.get_root());
        cout << endl;
    }
    return 0;
}