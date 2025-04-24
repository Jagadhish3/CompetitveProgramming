#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

node* create(int val){
    node* newnode=new node();
    newnode->data=val;
    newnode->left=newnode->right=NULL;
    return newnode;
}

node* build(){
    int ele;
    cin>>ele;

    if(ele==-1) return NULL;

    queue<node*> q;
    node* root=create(ele);
    q.push(root);

    while(!q.empty()){
        node* curr=q.front();
        q.pop();
        int l,r;
        cin>>l>>r;

        if(l!=-1){
            curr->left = create(l);
            q.push(curr->left);
        }

        if(r!=-1){
            curr->right = create(r);
            q.push(curr->right);
        }

    }

    return root;
}



void preorder(node* root){
    if(root==NULL) return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void preorderbfs(node* root){
    if(root==NULL) return;

    stack<node*> q;
    q.push(root);

    while(!q.empty()){
        node* curr = q.top();
        q.pop();
        cout<<curr->data<<" ";

        if(curr->right) q.push(curr->right);
        if(curr->left)  q.push(curr->left);
    }
}


int main(){
    node* root=build();
    preorderbfs(root);
}