#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {

    vector<int> dist(V, INT_MAX);

    priority_queue<pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>> pq;

    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {

        int d = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        if (d > dist[node]) continue;

        for (auto it : adj[node]) {

            int adjNode = it[0];
            int edgeWeight = it[1];

            if (d + edgeWeight < dist[adjNode]) {

                dist[adjNode] = d + edgeWeight;

                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

int main() {

    int V = 3;
    int E = 3;

    vector<vector<int>> adj[V];

    vector<vector<int>> edges = {
        {0, 1, 1},
        {0, 2, 6},
        {1, 2, 3}
    };

    for (int i = 0; i < E; i++) {

        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    int S = 2;

    vector<int> ans = dijkstra(V, adj, S);

    cout << "Shortest distances from source " << S << ":" << endl;

    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " : " << ans[i] << endl;
    }

    return 0;
}