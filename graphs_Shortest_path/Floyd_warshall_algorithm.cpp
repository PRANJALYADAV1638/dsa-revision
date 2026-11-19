
#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>& matrix) {

   int n =matrix.size();
   for(int b=0;b<n;b++){
    for(int c=0;c<matrix[0].size();c++){
        if(matrix[b][c]==-1){
            matrix[b][c]=1e9;
        }
    }
   }
    for(int k=0;k<n;k++){
        for(int s=0;s<n;s++){
            for(int e =0;e<n;e++){
                if(matrix[s][k]!=1e9&&matrix[k][e]!=1e9){
                    matrix[s][e]=min(matrix[s][e],matrix[s][k]+matrix[k][e]);
                }
            }
        }
    }
    

    for(int b=0;b<n;b++){
            if(matrix[b][b]<0){
                cout<<"negative cycle detacted ";
                return ;
            
        }
    }
    for(int b=0;b<n;b++){
        for(int c=0;c<n;c++){
           if(matrix[b][c] == 1e9)
    cout << "INF ";
else
    cout << matrix[b][c] << " ";
        }
        cout<<endl;
    
   }
}

int main() {

    vector<vector<int>> matrix = {
        {0,  5, -1, 10},
        {-1, 0,  3, -1},
        {-1,-1,  0,  1},
        {-1,-1, -1,  0}
    };

    solve(matrix);

    return 0;
}

/*

notes 

in very shrt
Floyd-Warshall – Short Notes
Algorithm: Dynamic Programming.

Purpose: All-Pairs Shortest Path.

Graph: Directed / Undirected, Weighted.

Negative weights: Supported.

Negative cycle: Detected using matrix[i][i] < 0.

Formula:

d
i
s
t
[
i
]
[
j
]
=
min
⁡
(
d
i
s
t
[
i
]
[
j
]
,
d
i
s
t
[
i
]
[
k
]
+
d
i
s
t
[
k
]
[
j
]
)
dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j])
Loops: 3 nested loops (k, i, j).

INF: Represents no path (1e9).

Time Complexity: 
O
(
V
3
)
O(V 
3
 )

Space Complexity: 
O
(
V
2
)
O(V 
2
 )
*/

/*

simple


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(int n, vector<vector<int>>& edges) {

    vector<vector<pair<int,int>>> adj(n);

    // Build adjacency list
    for(auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); // Undirected graph
    }

    vector<vector<int>> ans(n, vector<int>(n, INT_MAX));

    // Run Dijkstra from every vertex
    for(int src = 0; src < n; src++) {

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> dist(n, INT_MAX);

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()) {

            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(d > dist[node]) continue;

            for(auto it : adj[node]) {

                int newnode = it.first;
                int wt = it.second;

                int newdist = d + wt;

                if(newdist < dist[newnode]) {

                    dist[newnode] = newdist;

                    pq.push({newdist, newnode});
                }
            }
        }

        ans[src] = dist;
    }

    return ans;
}

int main() {

    int n = 4;

    vector<vector<int>> edges = {
        {0, 1, 5},
        {1, 2, 3},
        {2, 3, 1},
        {0, 3, 10}
    };

    vector<vector<int>> ans = solve(n, edges);

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            if(ans[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << ans[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}


*/