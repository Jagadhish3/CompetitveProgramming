#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<int>& color, bool& isBipartite) {
    for (int neighbor : graph[node]) {
        if (color[neighbor] == 0) { // If not colored, color it opposite to the parent node
            color[neighbor] = color[node]==1 ?2:1;
            dfs(neighbor, graph, color, isBipartite);
        } else if (color[neighbor] == color[node]) { // If same color as parent, it's not bipartite
            isBipartite = false;
            return;
        }
    }
}

void bfs(int u,vector<vector<int>>& graph,vector<int>&color,bool& isbipar){
    queue<int> q;
    q.push(u);

    while(!q.empty()){
        int p=q.front();
        q.pop();
        for(int i=0;i<graph[p].size();i++){
            int v= graph[p][i];
            if(color[v]==0){
                color[v]=color[p]==1 ? 2:1;
                q.push(v);
            }else if(color[v]==color[p]){
                isbipar=false;
                return;
            }
        }
    }
}

// void bfs(int u, vector<vector<int>>& graph, vector<int>& color, bool& isBipartite) {
//     queue<int> q;
//     q.push(u);
//     color[u] = 1; // Assign an initial color

//     while (!q.empty()) {
//         int p = q.front();
//         q.pop();

//         for (int v : graph[p]) { // Iterate over adjacent nodes
//             if (color[v] == 0) { // If uncolored, assign opposite color
//                 color[v] = (color[p] == 1) ? 2 : 1;
//                 q.push(v);
//             } else if (color[v] == color[p]) { // If same color, graph isn't bipartite
//                 isBipartite = false;
//                 return;
//             }
//         }
//     }
// }

int main() {
    int n, edges;
    cin >> n >> edges;

    vector<vector<int>> graph(n);
    // cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Since it's an undirected graph
    }

    vector<int> color(n, 0); // -1 means uncolored
    bool isBipartite = true;

    for (int i = 0; i < n; i++) {
        if (color[i] == 0) { // If node is not colored, start DFS
            color[i] = 1;
            // dfs(i, graph, color, isBipartite);
            bfs(i, graph, color, isBipartite);
        }
    }

    if (isBipartite) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }
    for(int i:color){
        cout<<i<<" ";
    }
    return 0;
}
