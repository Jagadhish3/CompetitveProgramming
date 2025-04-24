#include <bits/stdc++.h>
using namespace std;

int findminDis(vector<int> dis, bool visited[4]) {
    int mini = INT16_MAX;
    int ver = -1;
    for (int i = 0; i < 4; i++) {
        if (dis[i] < mini && visited[i] == false) {
            mini = dis[i];
            ver = i;
        }
    }
    return ver;
}

void dijkstra(vector<pair<int, int>> graph[4], int s, vector<int>& dis) {
    bool visited[4] = {};
    dis[s] = 0;

    for (int i = 0; i < 4; i++) {
        int v = findminDis(dis, visited);
        if (v == -1) continue;
        visited[v] = true;

        for (int j = 0; j < graph[v].size(); j++) {
            int ver = graph[v][j].first;
            int wt = graph[v][j].second;
            if ((dis[v] != INT16_MAX) && (dis[v] + wt < dis[ver])) {
                dis[ver] = dis[v] + wt;
            }
        }
    }
}

int main() {
    int n = 4;
    vector<pair<int, int>> graph[4];

    int edges;
    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges as: from to weight\n";
    for (int i = 0; i < edges; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        graph[u].push_back({v, wt});
        // graph[v].push_back({u, wt}); 
    }

    vector<int> dis(4, INT16_MAX);
    dijkstra(graph, 0, dis);

    cout << "Shortest distances from source 0:\n";
    for (int i = 0; i < 4; i++) {
        cout << "Node " << i << " : " << dis[i] << "\n";
    }

    return 0;
}
