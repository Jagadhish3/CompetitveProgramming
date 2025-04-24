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

void postorder(node* root){
    if(root==NULL) return;

    cout<<root->data<<" ";
    postorder(root->left);
    postorder(root->right);
}

void postorderbfs(node* root){
    if(root==NULL) return;

    stack<node*> s1,s2;
    s1.push(root);

    while(!s1.empty()){
        node* curr = s1.top();
        s1.pop();
        s2.push(curr);

        if(curr->left)  s1.push(curr->left);
        if(curr->right) s1.push(curr->right);
    }

    while(!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}


int main(){
    node* root=build();
    postorderbfs(root);
}