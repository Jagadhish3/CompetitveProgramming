#include <iostream>
using namespace std;

// Define a Node structure
struct Node {
    int data;
    Node *next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Function to insert a node at the end of the linked list
void insertAtEnd(Node *&head, int value) {
    Node *newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Recursive function to reverse the linked list
Node* reverseRec(Node *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    Node *newHead = reverseRec(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = nullptr;
    
    return newHead;
}

// Function to reverse the linked list
void reverse(Node *&head) {
    head = reverseRec(head);
}

// Function to display the linked list
void display(Node *head) {
    if (head == nullptr) {
        cout << "Linked List is empty" << endl;
        return;
    }
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to free the allocated memory for the linked list
void freeList(Node *head) {
    Node *temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node *head = nullptr;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    cout << "Original Linked List: ";
    display(head);

    reverse(head);
    cout << "Reversed Linked List: ";
    display(head);

    // Free allocated memory
    freeList(head);
    return 0;
}