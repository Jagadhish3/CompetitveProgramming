#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

node* add(int val){
    node* newnode = new node();
    newnode->data=val;
    newnode->left=newnode->right=NULL;
    return newnode;
}

node* level(){
    int input;
    cin>>input;

    if(input==-1) return NULL;

    queue<node*> q;
    node* newnode = add(input);
    q.push(newnode);

    while(!q.empty()){
        node* curr = q.front();
        q.pop();

        int l,r;
        cin>>l>>r;

        if(l!=-1){
            curr->left = add(l);
            q.push(curr->left);
        }

        if(r!=-1){
            curr->right = add(r);
            q.push(curr->right);
        }
    }
    return newnode;
}
// Node *lca(Node *root, int v1,int v2) {
    
//     if(root==NULL || root->data==v1 || root->data==v2){
//         return root;
//     }
    
//     Node* left = lca(root->left,v1,v2);
//     Node* right = lca(root->right,v1,v2);
    
//     if(left==NULL){
//         return right;
//     }
//     else if(right==NULL){
//         return left;
//     }
    
//         return root;
    
// }
node* lca(node* root, node* n1,node* n2){
    if(root==NULL) return root;
    if(root->data>n1->data && root->data>n2->data){
        return lca(root->left,n1,n2);
    }
    if(root->data<n1->data && root->data<n2->data){
        return lca(root->right,n1,n2);
    }

    return root;
}
node* bfs(node* curr, node* n1, node* n2){
    if(curr==NULL) return curr;
    while(true){
        
        if(curr->data>n1->data && curr->data>n2->data){
            curr=curr->left;
        }else if(curr->data<n1->data && curr->data<n2->data){
            curr=curr->right;
        }else{
            return curr;
        }
    }
}

int main(){
    node* root = level();
    int m, n;
    cin >> m >> n;
    node* x = add(m);
    node* y = add(n);
    node* res = bfs(root, x, y);
    cout << res->data;
}
