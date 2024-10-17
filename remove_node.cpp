#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;

    node(int ele){
        data = ele;
        next = nullptr;
    }
}*head = nullptr;

node* push(int data){
    node* newnode = new node(data);

    if(head==nullptr){
        head = newnode;
        return newnode;
    }else{
        head->next = newnode;
        head=newnode;
    }
    return newnode;
}

void display(node* head){
    node* curr = head;
    while(curr->next!=nullptr){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}

void remove(node* head,int n){
    node* slow = head;
    node* fast = head;

    int cnt = 0;
    while(cnt<=n){
        fast = fast->next;
        cnt++;
    }

    while(fast!=nullptr){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next = slow->next->next;
    
}


int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    int n=2;
    remove(head,n);
    display(head);

}