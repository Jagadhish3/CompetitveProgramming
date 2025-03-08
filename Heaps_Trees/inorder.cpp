#include<iostream>
#include<stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    
};

// TreeNode *prev = NULL;

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
// bool isBst(TreeNode* root){
//     stack<TreeNode*> s;
//     while(root!=NULL || !s.empty()){
//         while(root!=NULL){
//         s.push(root);
//         root=root->left;
//         }

//     root=s.top();
//     s.pop();
//     if(prev!=NULL && prev->val>=root->val){
//         return false;
//     }
//     prev = root;
//     root=root->right;
//     }
// }

bool isbst(TreeNode* root,int maxi, int mini){
    if(root==NULL){
        return true;
    }
    if(root->val<mini || root->val>maxi) return false;

    return isbst(root->left,root->val,mini)&&isbst(root->right,maxi,root->val);
}




void inorder(TreeNode* root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
    // cout<<root->val<<"END"<<endl;
}
int main(){
    TreeNode* root =TreeeNode(50);
    root->left =TreeeNode(40);
    root->left->left =TreeeNode(35);
    root->right =TreeeNode(60);
    root->left->right =TreeeNode(45);
    root->left->right->left =TreeeNode(40);
    root->right->right =TreeeNode(65);

    int maxi = INT8_MAX;
    int mini = INT8_MIN;
    bool res = isbst(root,maxi,mini);

    cout<<res;
    // inorder(root);
    // cout<<endl;
    // iterative_inorder(root);

}