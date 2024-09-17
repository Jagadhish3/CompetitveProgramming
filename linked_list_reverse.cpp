#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;

    node(int val){
        data = val;
        next = nullptr;
    }
};

void insertATEnd(int val){
    node* head = nullptr;
   
    node* newnode = new node(val);
    if(head==nullptr){
        head = newnode;
       }
    node* curr = head;
    while(curr->next!=nullptr){
        curr=curr->next;
    }
    curr->next=newnode;
}

node* rev(node* node){
    if(node==nullptr||node->next==nullptr){
        return node;
    }
    node* test = rev(node->next);
    node->next->next = node;
    node->next = nullptr;
    return test;
}

void reverse(){
    head = rev(head);
}