#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
int main(){
    node* head = nullptr;
    node* curr = nullptr;

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;

        node* newnode = new node;
        newnode->data=ele;
        newnode->next=nullptr;

        if(head==nullptr){
            head=newnode;
        }else{
            curr->next=newnode;
        }
        curr=newnode;
    }

    curr=head;
    while(curr!=nullptr){
        cout<<curr->data<<" ";
        curr=curr->next;
    }

}