#include<bits/stdc++.h>
using namespace std;


void dijkstra(vector<pair<int,int>> graph[], vector<int>& dis, int s){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dis[s] = 0;
    pq.push({dis[s], s});

    while (!pq.empty()) {
        int vertex = pq.top().second;
        int cur_dis = pq.top().first;
        pq.pop();

        for (int i = 0; i < graph[vertex].size(); i++) {
            int ver = graph[vertex][i].first;
            int wt = graph[vertex][i].second;

            if (dis[ver] > cur_dis + wt) {
                dis[ver] = cur_dis + wt;
                pq.push({dis[ver], ver});
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
    dijkstra(graph, dis, 0);

    cout << "Shortest distances from source 0:\n";
    for (int i = 0; i < 4; i++) {
        cout << "Node " << i << " : " << dis[i] << "\n";
    }

    return 0;
}
