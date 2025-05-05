// #include<bits/stdc++.h>
// using namespace std;

// struct node{
//     int data;
//     node* left;
//     node* right;
// };

// node* add(int val){
//     node* newnode = new node();
//     newnode->left = nullptr;
//     newnode->right = nullptr;
//     return newnode;
// }

// node* level(){
//     int input;
//     cin>>input;

//     if(input==-1) return NULL;

//     node* root = add(input);
//     queue<node*> q;
//     q.push(root);

//     while(!q.empty()){
//         node* curr = q.front();
//         q.pop();

//         int l,r;
//         cin>>l>>r;

//         if(l!=-1){
//             node* left = add(l);
//             q.push(left);
//         }
//         if(r!=-1){
//             node* right = add(r);
//             q.push(right);
//         }
//     }

//     return root;

// }

// int main(){
//     node* root = level();
// }


#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include<bits/stdc++.h>
using namespace std;

void diji(vector<pair<int,int>> graph[],vector<int>& dis,int s){
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dis[s]=0;
    pq.push({dis[s],s});

    while(!pq.empty()){
        int vertex = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        for(int i=0;i<graph[vertex].size();i++){
            int ver = graph[vertex][i].first;
            int wt = graph[vertex][i].second;


            if(dis[ver]>dist+wt){
                dis[ver]=dist+wt;
                pq.push({dis[ver],ver});
            }
        }
    }
}
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isPrime(int num){
    if (num<2) {
        return false;
    }
    for (int i=2;i*i<=num;i++) {
        if (num%i==0){
            return false;
        }
    }
    return true;
}

Node* buildTree(vector<vector<int>>& nodes, unordered_map<int, Node*>& nodeMap) {
    Node* root= nullptr;
    for (auto& child :nodes) {
        int parent =child[0], left=child[1], right = child[2];
        if (nodeMap.find(parent) == nodeMap.end())
            nodeMap[parent] = new Node(parent);
        if (!root) root = nodeMap[parent];

        if (left != -1) {
            nodeMap[left] = new Node(left);
            nodeMap[parent]->left = nodeMap[left];
        }
        if (right != -1) {
            nodeMap[right] = new Node(right);
            nodeMap[parent]->right = nodeMap[right];
        }
    }
    return root;
}

void inorder(Node* root, vector<int>& inorderList, unordered_map<int, int>& parentMap, int parent = -1) {
    if (!root) return;
    inorder(root->left, inorderList, parentMap, root->data);
    inorderList.push_back(root->data);
    parentMap[root->data] = parent;
    inorder(root->right, inorderList, parentMap, root->data);
}

void postorder(Node* root, vector<int>& postorderList) {
    if (!root) return;
    postorder(root->left, postorderList);
    postorder(root->right, postorderList);
    postorderList.push_back(root->data);
}

int main() {
    
    int N;
    cin >> N;
    vector<vector<int>> nodes(N, vector<int>(3));
    unordered_map<int, Node*> nodeMap;

    for (int i = 0; i < N; i++)
        cin >> nodes[i][0] >> nodes[i][1] >> nodes[i][2];

    Node* root = buildTree(nodes, nodeMap);

    int Q;
    cin >> Q;
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++) cin >> queries[i];

    vector<int> inorderList, postorderList;
    unordered_map<int, int> parentMap;
    inorder(root, inorderList, parentMap);
    postorder(root, postorderList);

    vector<int> primes;
    for (int num : inorderList)
        if (isPrime(num)) primes.push_back(num);

    for (int k : queries) {
        if (k > primes.size()||k <= 0)
            cout << "-1\n";
        else
            cout << primes[k-1]<<" "<<parentMap[primes[k -1]] << "\n";
    }

    for (int num : postorderList)
        cout << num << " ";
    
    return 0;
}