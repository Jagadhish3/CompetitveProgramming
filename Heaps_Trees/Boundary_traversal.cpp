#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

struct Treenode{
    int data;
    Treenode* left;
    Treenode* right;
};

Treenode* creat(int val){
    Treenode* newnode = new Treenode();
    newnode->data=val;
    newnode->left=newnode->right=NULL;

    return newnode;
}

Treenode* level(){
    int input;
    cin>>input;

    if(input==-1) return NULL;

    queue<Treenode*> q;
    Treenode* newnode = creat(input);
    q.push(newnode);

    while(!q.empty()){
        Treenode* curr = q.front();
        q.pop();

        int l,r;
        cin>>l>>r;

        if(l!=-1){
            curr->left = creat(l);
            q.push(curr->left);
        }

        if(r!=-1){
            curr->right = creat(r);
            q.push(curr->right);
        }
    }
    return newnode;
}

void left(Treenode* root, vector<int> &vec){
    if(root==NULL){
        return;
    }

    if(root->left){
        vec.push_back(root->data);
        left(root->left,vec);
    }else if(root->right){
        vec.push_back(root->data);
        left(root->right, vec);
    }
}

stack<int> st;
void right(Treenode* root){
    if(root==NULL) return;

    if(root->right){
        st.push(root->data);
        right(root->right);
    }else if(root->left){
        st.push(root->data);
        right(root->left);
    }
}

void leaf(Treenode* root, vector<int>& vec){
    if(root==NULL) return;

    if(root->left==NULL && root->right==NULL){
        vec.push_back(root->data);
    }

    if(root->left) leaf(root->left,vec);
    if(root->right) leaf(root->right, vec);
}

vector<int> boundary(Treenode* root){
    vector<int> vec;
    if(root==NULL) return vec;
    if(root->left==NULL && root->right==NULL){
        vec.push_back(root->data);
        return vec;
    }
    vec.push_back(root->data);

    left(root->left,vec);
    leaf(root,vec);
    right(root->right);
    while(!st.empty()){
        vec.push_back(st.top());
        st.pop();
    }

    return vec;
}
int main(){
    Treenode* root = level();
    vector<int> vec;
   vec = boundary(root);

    for(int i:vec){
        cout<<i<<" ";
    }

}