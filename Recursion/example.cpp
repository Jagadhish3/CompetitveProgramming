#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int LOG = 17; // log2(100000) ~ 17

vector<pair<int, int>> adj[MAXN]; // Adjacency list (node, weight)
int parent[MAXN][LOG]; // Binary lifting table
int depth[MAXN]; // Depth of each node
long long dist[MAXN]; // Distance from root
map<pair<int, int>, int> edgeCost; // Edge cost lookup

void dfs(int node, int par, int d, long long cost) {
    parent[node][0] = par;
    depth[node] = d;
    dist[node] = cost;
    
    for (auto [neighbor, weight] : adj[node]) {
        if (neighbor != par) {
            edgeCost[{min(node, neighbor), max(node, neighbor)}] = weight;
            dfs(neighbor, node, d + 1, cost + weight);
        }
    }
}

void preprocess(int N, int R) {
    memset(parent, -1, sizeof(parent));
    dfs(R, -1, 0, 0);

    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i < N; i++) {
            if (parent[i][j - 1] != -1) {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }
}

int findLCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    for (int j = LOG - 1; j >= 0; j--) {
        if (parent[u][j] != -1 && depth[parent[u][j]] >= depth[v]) {
            u = parent[u][j];
        }
    }

    if (u == v) return u;

    for (int j = LOG - 1; j >= 0; j--) {
        if (parent[u][j] != parent[v][j]) {
            u = parent[u][j];
            v = parent[v][j];
        }
    }
    return parent[u][0];
}

long long queryTransmissionCost(int A, int B) {
    int lca = findLCA(A, B);
    return dist[A] + dist[B] - 2 * dist[lca];
}

void updateTransmissionCost(int U, int V, int W) {
    pair<int, int> edge = {min(U, V), max(U, V)};
    int oldCost = edgeCost[edge];
    edgeCost[edge] = W;

    // Update the DFS distances
    queue<int> q;
    vector<bool> visited(MAXN, false);
    q.push(U);
    visited[U] = true;
    dist[U] = (U == 0) ? 0 : dist[parent[U][0]] + edgeCost[{min(U, parent[U][0]), max(U, parent[U][0])}];

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto [neighbor, weight] : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                dist[neighbor] = dist[node] + edgeCost[{min(node, neighbor), max(node, neighbor)}];
                q.push(neighbor);
            }
        }
    }
}

int solve(int N, int R, int M, vector<vector<int>> edges, int Q, vector<vector<int>> queries) {
    // Build the graph
    for (auto& edge : edges) {
        int U = edge[0], V = edge[1], W = edge[2];
        adj[U].push_back({V, W});
        adj[V].push_back({U, W});
    }

    // Preprocess LCA and distances
    preprocess(N, R);

    long long totalSum = 0;
    for (auto& query : queries) {
        int type = query[0], A = query[1], B = query[2], W = query[3];

        if (type == 1) { // Query transmission cost
            totalSum += queryTransmissionCost(A, B);
        } else if (type == 2) { // Update transmission cost
            updateTransmissionCost(A, B, W);
        }
    }
    return totalSum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, R, M;
    cin >> N >> R;
    M = N - 1;

    vector<vector<int>> edges(M, vector<int>(3));
    for (int i = 0; i < M; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int Q;
    cin >> Q;
    vector<vector<int>> queries(Q, vector<int>(4));
    for (int i = 0; i < Q; i++) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2] >> queries[i][3];
    }

    int result = solve(N, R, M, edges, Q, queries);
    cout << result << endl;
    
    return 0;
}
