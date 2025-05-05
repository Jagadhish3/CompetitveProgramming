#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void insert(Node*& root, int key) {
    if (!root) {
        root = new Node(key);
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (!temp->left) {
            temp->left = new Node(key);
            return;
        } else {
            q.push(temp->left);
        }
        if (!temp->right) {
            temp->right = new Node(key);
            return;
        } else {
            q.push(temp->right);
        }
    }
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int n, val;
    cout << "Enter number of initial nodes: ";
    cin >> n;
    cout << "Enter " << n << " node values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insert(root, val);
    }
    cout << "Inorder traversal before insertion: ";
    inorder(root);
    cout << endl;

    cout << "Enter value to insert: ";
    cin >> val;
    insert(root, val);

    cout << "Inorder traversal after insertion: ";
    inorder(root);
    cout << endl;

    return 0;
}