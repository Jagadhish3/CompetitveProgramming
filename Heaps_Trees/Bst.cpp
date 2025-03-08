#include<bits/stdc++.h>
using namespace std;


struct TreeNode{
    int val;
    TreeNode *left, *right;

};

TreeNode* addnode(int val){
    TreeNode* newNode = new TreeNode();
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder()



int main()