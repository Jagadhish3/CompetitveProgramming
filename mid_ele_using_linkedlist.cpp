#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
}*head = nullptr,* mid=nullptr;

int count;

Node* add(int data){
    Node* newnode = new Node;
    newnode->data = data;
    newnode->next = nullptr;
    newnode->prev = nullptr;
    return newnode;
}

void push(int val){
    Node* newnode = add(val);
    if(head==nullptr){
        head = newnode;

    }else{
       newnode->next = head;
       head = newnode;
       head->next->prev = newnode;
    }
    count++;

    if(mid==nullptr){
        mid=head;
    }else{
        if(count%2==0){
            mid=mid->pre;
        }
    }
}

void print(){
    Node* curr = head, *prev = nullptr;
    while(curr!=nullptr){
        cout<<curr->data<<" ";
        prev = curr;
        curr=curr->next;
    }
    curr = prev;
    while(curr!=nullptr){
        cout<<curr->data<<" ";
        curr=curr->prev;
    }
}

void pop(){
    if(head==nullptr){
        cout<<"Underflow";
        return;
    }
    Node* newnode = head;
    head = head->next;

    if(head!=nullptr){
        head->prev=nullptr;
    }
    cout<<"popped element "<<newnode->data;
    delete newnode;
    count--;
    if(count%2==0){
        mid=mid->next;
    }

}

int printmid(){
    if(mid==nullptr){
        return -1;
    }
    return mid->data;
}


int main(){
    Node* head = nullptr;
    Node* mid = nullptr;

    push(head,mid,5);
    push(head,mid,3);
    push(head,mid,8);
    Node* curr = head;
    cout<<mid->data;
}