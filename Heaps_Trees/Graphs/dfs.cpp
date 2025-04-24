#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(vector<bool>& visited, int u, vector<vector<int>>& adjList) {
    if (visited[u]) return;
    cout << u << " ";
    visited[u] = true;

    for (int v : adjList[u]) {  
        if (!visited[v]) {
            dfs(visited, v, adjList);
        }
    }
}

void bfs(vector<bool> &visited, int u, vector<vector<int>>& adjList) {
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        for (int v : adjList[curr]) {
            if (!visited[v]) {  
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<int>> adjList(nodes);  // Adjacency list

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // For undirected graph
    }
    int count = 0;
    vector<bool> visited(nodes, false);
    // cout << "BFS Traversal: ";
    
    //     bfs(visited, 0, adjList);
        
    // cout << endl;
    
    // visited.assign(nodes, false); // Reset visited array for DFS
    cout << "DFS Traversal: ";
    for(int i=0;i<nodes;i++){
        if(visited[i]!=true){
            dfs(visited, i, adjList);
            count++;
        }
    }
    cout << endl;
    cout<<count;

    return 0;
}

// int main() {
//     int nodes, edges;
//     cin >> nodes >> edges;

//     vector<vector<int>> adjList(nodes);  // Adjacency list

//     for (int i = 0; i < edges; i++) {
//         int u, v;
//         cin >> u >> v;
//         adjList[u].push_back(v);
//         adjList[v].push_back(u);  // For undirected graph
//     }

//     vector<bool> visited(nodes, false);
//     cout << "BFS Traversal: ";
//     bfs(visited, 0, adjList);
//     cout << endl;

//     visited.assign(nodes, false); // Reset visited array for DFS
//     cout << "DFS Traversal: ";
//     dfs(visited, 0, adjList);
//     cout << endl;

//     return 0;
// }