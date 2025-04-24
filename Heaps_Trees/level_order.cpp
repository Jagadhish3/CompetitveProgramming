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

// void levelorder(Treenode* root){
//     if(root==NULL) return;

//     queue<Treenode*> q;
//     q.push(root);

//     while(!q.empty()){
//         Treenode* curr = q.front();
//         q.pop();

//         cout<<curr->data<<" ";
        
//         if(curr->left) q.push(curr->left);
//         if(curr->right) q.push(curr->right);

//     }
// }

void levelorder(Treenode* root){
    queue<Treenode*> q;
    q.push(root);

    int level = 0;
    while(!q.empty()){
        int s=q.size();
        vector<int> vec;
        for(int i=0;i<s;i++){
            Treenode* curr=q.front();
            q.pop();

            vec.push_back(curr->data);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }

        if(level%2!=0){
            for(int i:vec){
                cout<<i<<" ";
            }
        }
            else{
                reverse(vec.begin(),vec.end());
                for(int i:vec){
                    cout<<i<<" ";
                }
            }
            level++;
    }
}



void inorderbfs(Treenode* root){
    stack<Treenode*> s;

    while(root!=NULL || !s.empty()){
        while(root!=NULL){
            s.push(root);
            root=root->left;
        }

        root=s.top();
        s.pop();
    cout<<root->data<<" ";
        root=root->right;
    }
}

int main(){
    Treenode* root = level();
    levelorder(root);
}