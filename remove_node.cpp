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

    if(head == nullptr){
        head = newnode;
    } else {
        node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return newnode;
}

void display(node* head){
    node* curr = head;
    while(curr != nullptr){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void remove(node* head, int n){
    node* slow = head;
    node* fast = head;

    // Move fast pointer 'n' nodes ahead
    for(int i = 0; i < n; i++){
        if(fast == nullptr) return; // If n is greater than the list size
        fast = fast->next;
    }

    // If we need to remove the head node
    if(fast == nullptr){
        head = head->next;
        delete slow;
        return;
    }

    // Move both slow and fast pointers until fast reaches the end
    while(fast->next != nullptr){
        slow = slow->next;
        fast = fast->next;
    }

    // Remove the nth node from the end
    node* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    int n = 2;  // Remove 2nd node from the end
    remove(head, n);
    display(head);

    return 0;
}
