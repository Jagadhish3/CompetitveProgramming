#include<bits/stdc++.h>
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


void bfs(Node* root){
    
    queue<Node*> q;
    q.push(root->left);
    q.push(root->right);
    bool isvalid = true;

    while(!q.empty()){
        Node* node1 = q.front();
        q.pop();
        Node* node2 = q.front();
        q.pop();
        if(node1==NULL && node2==NULL){
            continue;
        }
        if(node1==NULL||node2==NULL){
            isvalid=false;
            break;
        }
        if(node1->data!=node2->data){
            isvalid = false;
            break;
        }

        q.push(node1->left);
        q.push(node2->right);

        q.push(node1->right);
        q.push(node2->left);

    }
    cout<<isvalid;
}

int main(){
    Node* root = add(1);
    root->left = add(2);
    root->right = add(2);
    root->left->left = add(3);
    root->right->right=add(3);
    root->left->right=add(4);
    root->right->left=add(4);
    
    bfs(root);
    
}

