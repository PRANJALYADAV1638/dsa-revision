/*
📘 GRAPH IN DSA — SHORT NOTES & QUICK REVISION
1. Graph Introduction

Graph = Vertices (V) + Edges (E)

Vertex: Node
Edge: Connection between nodes
Applications: Google Maps, social networks, computer networks.
2. Types of Graphs
Type	Meaning
Undirected	No direction
Directed	Edges have direction
Weighted	Edges have weights/cost
Unweighted	Edges have no weights
Connected	All vertices are reachable
Disconnected	Multiple components
Cyclic	Contains a cycle
DAG	Directed Acyclic Graph
Tree	Connected + Undirected + Acyclic

Tree with V vertices has V − 1 edges.

3. Graph Representation

Adjacency List — Most commonly used

vector<vector<int>> adj(V);

adj[0].push_back(1);
adj[1].push_back(0);
Adjacency List: O(V + E) space
Adjacency Matrix: O(V²) space
Edge List: Stores edges as (u, v) or (u, v, weight).
4. BFS vs DFS
BFS	DFS
Queue	Recursion / Stack
Level-by-level	Goes deep, then backtracks
Unweighted shortest path	Cycle detection, components
O(V + E)	O(V + E)

BFS: Breadth First Search
DFS: Depth First Search

5. Important Graph Algorithms
Problem	Algorithm
Traversal	BFS / DFS
Connected Components	BFS / DFS / DSU
Undirected Cycle	DFS + Parent
Directed Cycle	DFS + Recursion Stack
Unweighted Shortest Path	BFS
Weighted Shortest Path	Dijkstra
Negative Edge Weights	Bellman-Ford
All-Pairs Shortest Path	Floyd-Warshall
Dependency Ordering	Topological Sort
Minimum Spanning Tree	Prim's / Kruskal's
Component Management	DSU
Bipartite Graph	BFS / DFS + Coloring
Strongly Connected Components	Kosaraju's / Tarjan's
6. Important Formulas
Undirected graph: Sum of degrees = 2E
Directed graph: Sum of indegrees = Sum of outdegrees = E
Tree: E = V - 1
BFS/DFS time: O(V + E)
Dijkstra with priority queue: O((V+E) log V)
Floyd-Warshall: O(V³)
7. Must-Do Interview Problems
BFS of Graph
DFS of Graph
Number of Provinces
Number of Islands
Flood Fill
Cycle Detection — Directed & Undirected
Is Graph Bipartite?
Course Schedule I & II
Shortest Path in Unweighted Graph
Dijkstra's Algorithm
Minimum Spanning Tree
Disjoint Set Union (DSU)
Rotten Oranges
Topological Sort
🔥 Last-Minute Revision
Queue → BFS
Recursion/Stack → DFS
Unweighted shortest path → BFS
Non-negative weights → Dijkstra
Negative weights → Bellman-Ford
DAG → Topological Sort
MST → Prim's / Kruskal's
Union-Find → DSU

Recommended order: Representation → BFS → DFS → Cycle Detection → Bipartite → Topological Sort → Shortest Path → DSU → MST → SCC.
*/