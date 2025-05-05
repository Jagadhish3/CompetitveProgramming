#include <bits/stdc++.h>
using namespace std;

bool dfsDirected(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfsDirected(neighbor, adj, visited, recStack))
                return true;
        } else if (recStack[neighbor]) {
            return true; // Cycle detected
        }
    }

    recStack[node] = false;
    return false;
}

bool hasCycleDirected(int V, vector<vector<int>> &adj) {
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (dfsDirected(i, adj, visited, recStack))
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
    cout << "Enter " << E << " directed edges (u -> v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Directed
    }

    if (hasCycleDirected(V, adj))
        cout << "Cycle detected in the directed graph." << endl;
    else
        cout << "No cycle in the directed graph." << endl;

    return 0;
}
