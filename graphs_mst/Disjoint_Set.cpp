
/*
smaller attach because agr bda chota k attach hoga to tree ek side jyada bda ho jaiga*/
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {

    vector<int> parent;
    vector<int> rank;
    vector<int> size;

public:

    DisjointSet(int n) {

        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findparent(int u) {

        if (parent[u] == u) {
            return u;
        }

        return parent[u] = findparent(parent[u]);
    }

    void unionByRank(int u, int v) {

        int p_u = findparent(u);
        int p_v = findparent(v);

        if (p_u == p_v) return;

        if (rank[p_u] < rank[p_v]) {
            parent[p_u] = p_v;
        }

        else if (rank[p_u] > rank[p_v]) {
            parent[p_v] = p_u;
        }

        else {
            parent[p_v] = p_u;
            rank[p_u]++;
        }
    }

    void unionBySize(int u, int v) {

        int p_u = findparent(u);
        int p_v = findparent(v);

        if (p_u == p_v) return;

        if (size[p_u] < size[p_v]) {

            parent[p_u] = p_v;
            size[p_v] += size[p_u];

        }

        else {

            parent[p_v] = p_u;
            size[p_u] += size[p_v];

        }
    }

    bool find(int u, int v) {

        return findparent(u) == findparent(v);
    }
};

int main() {

    DisjointSet ds(5);

    ds.unionByRank(0, 1);

    ds.unionBySize(2, 3);

    cout << boolalpha;

    cout << ds.find(0, 1) << endl;

    cout << ds.find(0, 3) << endl;

    return 0;
}