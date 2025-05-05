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

Node* findDeepest(Node* root, Node*& parent) {
    queue<pair<Node*, Node*>> q;
    q.push({root, nullptr});
    Node* last = nullptr;
    while (!q.empty()) {
        Node* curr = q.front().first;
        Node* par = q.front().second;
        q.pop();
        last = curr;
        parent = par;
        if (curr->left) q.push({curr->left, curr});
        if (curr->right) q.push({curr->right, curr});
    }
    return last;
}

void deleteDeepest(Node* root, Node* target) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        if (curr->left) {
            if (curr->left == target) {
                curr->left = nullptr;
                return;
            } else {
                q.push(curr->left);
            }
        }
        if (curr->right) {
            if (curr->right == target) {
                curr->right = nullptr;
                return;
            } else {
                q.push(curr->right);
            }
        }
    }
}

void deleteNode(Node*& root, int key) {
    if (!root) return;
    if (!root->left && !root->right) {
        if (root->data == key) {
            delete root;
            root = nullptr;
        }
        return;
    }
    queue<Node*> q;
    q.push(root);
    Node* target = nullptr;
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp->data == key) target = temp;
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    if (target) {
        Node* parent = nullptr;
        Node* deepest = findDeepest(root, parent);
        target->data = deepest->data;
        deleteDeepest(root, deepest);
    }
}

int main() {
    Node* root = nullptr;
    int n, val, delVal;
    cout << "Enter number of initial nodes: ";
    cin >> n;
    cout << "Enter " << n << " node values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insert(root, val);
    }

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    cout << "Enter value to delete: ";
    cin >> delVal;
    deleteNode(root, delVal);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}