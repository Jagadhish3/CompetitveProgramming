#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;
Node* mid = nullptr;
int count = 0;

Node* add(int data){
    Node* newnode = new Node;
    newnode->data = data;
    newnode->next = nullptr;
    newnode->prev = nullptr;
    return newnode;
}

void push(int val){
    Node* newnode = add(val);
    if (head == nullptr) {
        head = newnode;
        mid = newnode;  // Initialize mid to the first node
    } else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    count++;

    // Update mid
    if (count % 2 == 0) {
        mid = mid->prev;  // Move mid left when count is even
    }
}

void print(){
    Node* curr = head;
    cout << "List in forward direction: ";
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }

    cout << "\nList in backward direction: ";
    curr = mid;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << endl;
}

void pop(){
    if (head == nullptr) {
        cout << "Underflow\n";
        return;
    }

    Node* newnode = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }
    cout << "Popped element: " << newnode->data << endl;
    delete newnode;
    count--;

    // Update mid
    if (count % 2 == 0) {
        mid = mid->next;  // Move mid right when count is even
    }
}

int printmid(){
    if (mid == nullptr) {
        return -1;
    }
    return mid->data;
}

int main(){
    push(5);
    push(3);
    push(8);

    cout << "Middle element: " << printmid() << endl;
    print();

    pop();
    cout << "Middle element: " << printmid() << endl;
    print();

    return 0;
}
