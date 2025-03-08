#include<iostream>
using namespace std;

// Define the node structure
struct node{
    int data;
    node* next;

    node(int val) {
        data = val;
        next = nullptr;
    }
};

// Global head pointer
node* head = nullptr;

// Function to insert a node at the end
void insertATEnd(int val) {
    node* newnode = new node(val);

    if (head == nullptr) {
        head = newnode;  // If the list is empty, new node becomes the head
        return;
    }

    // Traverse to the end of the list
    node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }

    // Insert new node at the end
    curr->next = newnode;
}

// Recursive function to reverse the list
node* rev(node* curr) {
    if (curr == nullptr || curr->next == nullptr) {
        return curr;
    }
    node* rest = rev(curr->next);  // Recurse to the end of the list
    curr->next->next = curr;  // Reverse the current node's pointer
    curr->next = nullptr;  // Set the current node's next to nullptr
    return rest;  // Return the new head
}

// Function to reverse the list
void reverse() {
    head = rev(head);  // Update the global head with the new head
}

// Function to print the list
void printList() {
    node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    // Insert nodes
    insertATEnd(1);
    insertATEnd(2);
    insertATEnd(3);
    insertATEnd(4);
    
    // Print original list
    cout << "Original List: ";
    printList();

    // Reverse the list
    reverse();

    // Print reversed list
    cout << "Reversed List: ";
    printList();

    return 0;
}
