#include<bits/stdc++.h>
using namespace std;

// Function to check if the graph has Eulerian Cycle or Path
void eulerianPathCycle(vector<vector<int>> &adj, int V) {
    int odd_degree_count = 0;

    for(int i = 0; i < V; i++) {
        if(adj[i].size() % 2 != 0)
            odd_degree_count++;
    }

    if(odd_degree_count == 0) {
        cout << "Graph has an Eulerian cycle." << endl;
    } else if(odd_degree_count == 2) {
        cout << "Graph has an Eulerian path." << endl;
    } else {
        cout << "Graph is neither Eulerian path nor cycle." << endl;
    }
}

void addEdge(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    vector<vector<int>> adj(V);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v):" << endl;
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    eulerianPathCycle(adj, V);
    return 0;
}
