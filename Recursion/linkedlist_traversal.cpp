#include<iostream>
#include<vector>
using namespace std;

struct node{
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

node* head =NULL;
node* curr = NULL;

void insert(vector<int> vec,int n){
        for(int i=0;i<n;i++){
            node* newnode = new node(vec[i]);
            if(head==nullptr){
                head=newnode;
                curr=newnode;
            }else{
                curr->next = newnode;
                curr=curr->next;
            }
        }
}

void print(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    insert(vec,n);
    print(head);
    
}