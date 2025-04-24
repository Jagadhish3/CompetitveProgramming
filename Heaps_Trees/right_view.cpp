#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* add(int val){
    Node* newnode = new Node();
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;
}

void rightview(Node* root){
    if(root==NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);

    vector<int> v;
    while(!q.empty()){
        int size = q.size();

        for(int i=0;i<size;i++){
            Node* curr=q.front();
            q.pop();
            if(i==size-1) v.push_back(curr->data);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }

    }
    for(int i:v){
        cout<<i<<" ";
    }
}

// void dfs_rightview(Node* root,int i,vector<int>& v){
//     if(root==NULL){
//         return;
//     }

//     if(i==v.size()){
//         v.push_back(root->data);
//     }else{
//         v[i]=root->data;
//     }
//     dfs_rightview(root->left,i++,v);
//     dfs_rightview(root->right,i++,v);

// }

int main(){
    Node* root=add(5);
    root->left=add(3);
    root->left->left=add(4);
    root->right=add(7);
    root->right->right=add(8);
    vector<int> v;

    rightview(root);
    // dfs_rightview(root,0,v);
    // for(int i:v){
    //    cout<<i<<" ";
    // }
    
}