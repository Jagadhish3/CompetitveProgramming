#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, visited))
                return true;
        } else if (neighbor != parent) {
            return true; // Cycle detected
        }
    }
    return false;
}

bool hasCycleUndirected(int V, vector<vector<int>> &adj) {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited))
                return true;
        }
    }
    return false;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);
    cout << "Enter " << E << " edges (undirected):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Since undirected
    }

    if (hasCycleUndirected(V, adj))
        cout << "Cycle detected in the undirected graph." << endl;
    else
        cout << "No cycle in the undirected graph." << endl;

    return 0;
}
