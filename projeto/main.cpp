#include <iostream>
#include <string>

#include "treenode.h"
#include "treenode_subclasses.h"

int main(){
    string readExp;

    cout << "Please enter a expression: \n";
    cin >> readExp;

    TreeNode* rootExp = new TreeNodeRoot(readExp);
}