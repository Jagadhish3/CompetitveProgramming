#include<iostream>
using namespace std;

struct node{
    int val;
    node* next;
};

node* push(node* head, int ele){
    node* newnode = new node;
    newnode->val = ele;
    newnode->next = head;
    head = newnode;
    return head;
}

int pop(node** head){
    if (*head == nullptr) {
        cout << "Stack underflow" << endl;
        return -1; 
    }

    int poppedValue = (*head)->val;
    node* temp = *head;
    *head = (*head)->next;
    delete temp;
    
    return poppedValue;
}

int main()
{
    node* head = nullptr;
    
    head = push(head, 5);
    head = push(head, 4);
    head = push(head, 8);
    head = push(head, 1);

    cout << "Popped: " << pop(&head) << endl;
    cout << "Popped: " << pop(&head) << endl; 
    
    return 0;
}
