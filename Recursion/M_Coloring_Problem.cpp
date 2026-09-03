#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSafe(int node, int color, vector<int> &colors,
                vector<int> adj[]) {

        for (int neighbour : adj[node]) {
            if (colors[neighbour] == color)
                return false;
        }

        return true;
    }

    bool solve(int node, int n, int m,
               vector<int> adj[],
               vector<int> &colors) {

        if (node == n)
            return true;

        for (int color = 1; color <= m; color++) {

            if (isSafe(node, color, colors, adj)) {

                colors[node] = color;

                if (solve(node + 1, n, m, adj, colors))
                    return true;

                colors[node] = 0;
            }
        }

        return false;
    }

    bool graphColoring(vector<vector<int>> &edges, int m, int n) {

        vector<int> adj[n];

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> colors(n, 0);

        return solve(0, n, m, adj, colors);
    }
};

int main() {

    int n, e, m;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> edges;

    cout << "Enter edges (u v):\n";

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    cout << "Enter number of colors: ";
    cin >> m;

    Solution obj;

    if (obj.graphColoring(edges, m, n))
        cout << "Coloring is Possible\n";
    else
        cout << "Coloring is Not Possible\n";

    return 0;
}