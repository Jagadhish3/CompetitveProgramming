#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void bellman(vector<pair<int, int>> graph[], vector<int> &dis, int start, int n) {
    dis[start] = 0;
    for (int i = 0; i < n - 1; i++) { // Relax edges up to (n-1) times
        for (int u = 0; u < n; u++) {
            for (auto edge : graph[u]) {
                int v = edge.first; 
                int wt = edge.second; 
                if (dis[u] != INT_MAX && dis[v] > dis[u] + wt) {
                    dis[v] = dis[u] + wt;
                }
            }
        }
    }
}

int main() {
    int n, edges;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> edges;

    vector<pair<int, int>> graph[n]; // Adjacency list representation

    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        graph[u].push_back({v, wt}); // Storing edges with weights
    }

    vector<int> dis(n, INT_MAX);
    bellman(graph, dis, 0, n);

    cout << "Shortest distances from node 0:" << endl;
    for (int i = 0; i < n; i++) {
        if (dis[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dis[i] << " ";
    }
    cout << endl;

    return 0;
}
