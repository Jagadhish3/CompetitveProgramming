#include<iostream>
#include<stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    
};


TreeNode* TreeeNode(int val){
    TreeNode* newNode = new TreeNode();
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;

}

void iterative_inorder(TreeNode* root){
    stack<TreeNode*> s;
    while(root!=NULL || !s.empty()){
        while(root!=NULL){
        s.push(root);
        root=root->left;
        }

    root=s.top();
    s.pop();
    cout<<root->val<<" ";
    root=root->right;
    }
}

void inorderdfs(TreeNode* root){
    if(root==NULL) return;

    inorderdfs(root->left);
    cout<<root->val<<" ";
    inorderdfs(root->right);
}

int main(){
    TreeNode* root =TreeeNode(50);
    root->left =TreeeNode(40);
    root->left->left =TreeeNode(35);
    root->right =TreeeNode(60);
    root->left->right =TreeeNode(45);
    root->left->right->left =TreeeNode(40);
    root->right->right =TreeeNode(65);

    inorderdfs(root);
    cout<<endl;
    iterative_inorder(root);

}