#include <iostream>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node* next; // This will store inorder successor

    Node(int val) {
        data = val;
        left = right = next = nullptr;
    }
};

// Recursive function to set inorder successors
void populateNext(Node* root, Node*& next) {
    if (!root) return;

    // Reverse inorder: right -> root -> left
    populateNext(root->right, next);

    // Set the next of current node to previously visited node
    root->next = next;

    // Update next to current node before going to left subtree
    next = root;

    populateNext(root->left, next);
}

// Wrapper to initiate with null successor
void populateInorderSuccessor(Node* root) {
    Node* next = nullptr;
    populateNext(root, next);
}

// Utility function to print inorder traversal with successors
void printInorderSuccessors(Node* root) {
    if (!root) return;
    printInorderSuccessors(root->left);
    cout << "Node " << root->data << " -> Successor ";
    if (root->next)
        cout << root->next->data << endl;
    else
        cout << "NULL" << endl;
    printInorderSuccessors(root->right);
}

// Sample usage
int main() {
    /*
            10
           /  \
          5    15
         / \     \
        2   7     20
    */
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    populateInorderSuccessor(root);
    printInorderSuccessors(root);

    return 0;
}