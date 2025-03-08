#include<bits/stdc++.h>
using namespace std;

// int sum=0;
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

// void dfs(Node* root, int curr,int &sum){
//     if(root==NULL){
//         return;
//     }

//     curr=curr*10+root->data;
//     if(root->left==NULL && root->right==NULL){
//         sum+=curr;
//         return;
//     }

//     dfs(root->left,curr,sum);
//     dfs(root->right,curr,sum);

// }

// void bfs(Node* root){
//     if(root==NULL){
//         return;
//     }

//     queue<Node*> q1;
//     queue<int> q2;
//     q1.push(root);
//     q2.push(root->data);

//     while(!q1.empty()){
      
//             Node* curr = q1.front();
//             q1.pop();
//             int currsum=q2.front();
//             q2.pop();

//             if(curr->left==NULL && curr->right==NULL){
//                 sum+=currsum;
//             }
//             if(curr->left){
//                  q1.push(curr->left);
//                  q2.push(currsum*10+curr->left->data);
//             }
//             if(curr->right){
//                  q1.push(curr->right);
//                  q2.push(currsum*10+curr->right->data);
//             }      

//     }

// }

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
    // int sum=0;
    // dfs(root,0,sum);
    bfs(root);
    // if(isvalid){
    //     cout<<"Symmetric tree";
    // }else{
    //     cout<<"Not";
    // }
    // cout<<sum;
}

