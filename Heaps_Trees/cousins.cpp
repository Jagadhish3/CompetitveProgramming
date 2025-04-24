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


Node* x_parent = NULL;
Node* y_parent = NULL;
int x_lev = -1;
int y_lev = -1;
bool checkCousin(Node* root,Node* prev,int i,int x, int y){
  if(root==NULL){
    return false;
  }
    bool left=checkCousin(root->left,root,i+1,x,y);
    bool right=checkCousin(root->right,root,i+1,x,y);
    if(root->data == x){
        x_parent=prev;
        x_lev=i;
    }
    if(root->data == y){
        y_parent=prev;
        y_lev=i;
    }

if(x_parent!=y_parent && x_lev==y_lev){
    return true;
}
return left||right;

}

bool checkCousinbfs(Node* root, int x,int y){
    
    bool xfound=false;
    bool yfound=false;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int s=q.size();
        
        for(int i=0;i<s;i++){
            Node* curr = q.front();
            q.pop();

            if(curr->left!=NULL && curr->right!=NULL && ((curr->left->data==x && curr->right->data==y) || (curr->left->data==y && curr->right->data==x))){
                return false; 
            }
            
            if(curr->data==x) xfound=true;
            if(curr->data==y) yfound=true;
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    return xfound && yfound;
}

int main(){
    Node* root;

    root=add(5);
    root->left=add(3);
    root->left->left=add(4);
    // root->left->left->left=add(9);
    root->right=add(7);
    // root->right->right=add(8);
    // root->right->right->right=add(18);
    // vector<int> v;

    bool x=checkCousin(root,NULL,0,4,7);
    cout<<x;

    
}