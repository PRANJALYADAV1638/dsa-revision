#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
vector<vector<int>> adj(numCourses);
vector<int> indegree(numCourses, 0);

    for (auto it : prerequisites) {
        int u = it[1];
        int v = it[0];

        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;

    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        count++;

        for (auto neighbour : adj[node]) {
            indegree[neighbour]--;

            if (indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    return count == numCourses;
}


};

int main() {
int numCourses = 2;


vector<vector<int>> prerequisites = {
    {1, 0}
};

Solution obj;

if (obj.canFinish(numCourses, prerequisites)) {
    cout << "true";
} else {
    cout << "false";
}

return 0;


}
