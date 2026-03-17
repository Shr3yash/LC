#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

/*
========================================================
1. GRAPH REPRESENTATION
========================================================

Unweighted:
vector<vector<int>> adj(V);

Weighted:
vector<vector<pair<int,int>>> adj(V);   // {neighbor, weight}

Undirected:
adj[u].push_back(v);
adj[v].push_back(u);

Directed:
adj[u].push_back(v);
*/

/*========================================================
2. BFS TRAVERSAL
Use:
- level order traversal
- connected graph traversal
- unweighted shortest path
DS used:
- queue
- visited array
========================================================*/
vector<int> bfsTraversal(int V, vector<vector<int>>& adj, int src) {
    vector<int> vis(V, 0), order;
    queue<int> q;

    vis[src] = 1;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);

        for (int neigh : adj[node]) {
            if (!vis[neigh]) {
                vis[neigh] = 1;
                q.push(neigh);
            }
        }
    }
    return order;
}

/*========================================================
3. DFS TRAVERSAL
Use:
- traversal
- connected components
- cycle detection
DS used:
- recursion stack (implicit)
- visited array
========================================================*/
void dfsHelper(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& order) {
    vis[node] = 1;
    order.push_back(node);

    for (int neigh : adj[node]) {
        if (!vis[neigh]) {
            dfsHelper(neigh, adj, vis, order);
        }
    }
}

vector<int> dfsTraversal(int V, vector<vector<int>>& adj, int src) {
    vector<int> vis(V, 0), order;
    dfsHelper(src, adj, vis, order);
    return order;
}

/*========================================================
4. CONNECTED COMPONENTS (UNDIRECTED GRAPH)
Use:
- count disconnected groups
- number of provinces
DS used:
- DFS/BFS
- visited array
========================================================*/
void dfsComponent(int node, vector<vector<int>>& adj, vector<int>& vis) {
    vis[node] = 1;
    for (int neigh : adj[node]) {
        if (!vis[neigh]) dfsComponent(neigh, adj, vis);
    }
}

int countConnectedComponents(int V, vector<vector<int>>& adj) {
    vector<int> vis(V, 0);
    int components = 0;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            components++;
            dfsComponent(i, adj, vis);
        }
    }
    return components;
}

/*========================================================
5. CYCLE DETECTION IN UNDIRECTED GRAPH (DFS)
Use:
- detect cycle in undirected graph
DS used:
- visited array
- parent variable
========================================================*/
bool dfsCycleUndirected(int node, int parent, vector<vector<int>>& adj, vector<int>& vis) {
    vis[node] = 1;

    for (int neigh : adj[node]) {
        if (!vis[neigh]) {
            if (dfsCycleUndirected(neigh, node, adj, vis)) return true;
        } else if (neigh != parent) {
            return true;
        }
    }
    return false;
}

bool hasCycleUndirectedDFS(int V, vector<vector<int>>& adj) {
    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfsCycleUndirected(i, -1, adj, vis)) return true;
        }
    }
    return false;
}

/*========================================================
6. CYCLE DETECTION IN UNDIRECTED GRAPH (BFS)
DS used:
- queue of {node, parent}
- visited array
========================================================*/
bool hasCycleUndirectedBFS(int V, vector<vector<int>>& adj) {
    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++) {
        if (vis[i]) continue;

        queue<pair<int, int>> q; // {node, parent}
        q.push({i, -1});
        vis[i] = 1;

        while (!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();

            for (int neigh : adj[node]) {
                if (!vis[neigh]) {
                    vis[neigh] = 1;
                    q.push({neigh, node});
                } else if (neigh != parent) {
                    return true;
                }
            }
        }
    }
    return false;
}

/*========================================================
7. CYCLE DETECTION IN DIRECTED GRAPH (DFS)
Use:
- directed cycle detection
DS used:
- vis[]
- pathVis[]  (recursion path marker)
========================================================*/
bool dfsCycleDirected(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
    vis[node] = 1;
    pathVis[node] = 1;

    for (int neigh : adj[node]) {
        if (!vis[neigh]) {
            if (dfsCycleDirected(neigh, adj, vis, pathVis)) return true;
        } else if (pathVis[neigh]) {
            return true;
        }
    }

    pathVis[node] = 0;
    return false;
}

bool hasCycleDirectedDFS(int V, vector<vector<int>>& adj) {
    vector<int> vis(V, 0), pathVis(V, 0);

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfsCycleDirected(i, adj, vis, pathVis)) return true;
        }
    }
    return false;
}

/*========================================================
8. TOPOLOGICAL SORT (DFS + STACK)
Use:
- DAG ordering
- prerequisite ordering
- DAG shortest path
DS used:
- visited array
- stack
========================================================*/
void dfsTopo(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
    vis[node] = 1;

    for (int neigh : adj[node]) {
        if (!vis[neigh]) dfsTopo(neigh, adj, vis, st);
    }

    st.push(node);
}

vector<int> topoSortDFS(int V, vector<vector<int>>& adj) {
    vector<int> vis(V, 0), topo;
    stack<int> st;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) dfsTopo(i, adj, vis, st);
    }

    while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}

/*========================================================
9. TOPOLOGICAL SORT (KAHN'S ALGORITHM)
Use:
- DAG ordering
- cycle detection in directed graph
DS used:
- indegree[]
- queue
========================================================*/
vector<int> topoSortKahn(int V, vector<vector<int>>& adj) {
    vector<int> indegree(V, 0);

    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> topo;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (int neigh : adj[node]) {
            indegree[neigh]--;
            if (indegree[neigh] == 0) q.push(neigh);
        }
    }

    return topo; // if topo.size() < V => cycle exists
}

bool hasCycleDirectedKahn(int V, vector<vector<int>>& adj) {
    vector<int> topo = topoSortKahn(V, adj);
    return topo.size() < V;
}

/*========================================================
10. SHORTEST PATH IN UNWEIGHTED GRAPH
Use:
- minimum edges
- minimum steps
- grid shortest path (if each move cost same)
DS used:
- queue
- dist[]
- optional parent[]
========================================================*/
vector<int> shortestPathUnweighted(int V, vector<vector<int>>& adj, int src) {
    vector<int> dist(V, INF);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neigh : adj[node]) {
            if (dist[neigh] > dist[node] + 1) {
                dist[neigh] = dist[node] + 1;
                q.push(neigh);
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (dist[i] == INF) dist[i] = -1;
    }
    return dist;
}

/*========================================================
11. SHORTEST PATH + PATH RECONSTRUCTION (UNWEIGHTED)
Use:
- when actual route is needed
DS used:
- queue
- dist[]
- parent[]
========================================================*/
vector<int> shortestPathUnweightedRoute(int V, vector<vector<int>>& adj, int src, int dest) {
    vector<int> dist(V, INF), parent(V);
    queue<int> q;

    for (int i = 0; i < V; i++) parent[i] = i;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neigh : adj[node]) {
            if (dist[neigh] > dist[node] + 1) {
                dist[neigh] = dist[node] + 1;
                parent[neigh] = node;
                q.push(neigh);
            }
        }
    }

    if (dist[dest] == INF) return {};

    vector<int> path;
    int cur = dest;
    while (parent[cur] != cur) {
        path.push_back(cur);
        cur = parent[cur];
    }
    path.push_back(src);
    reverse(path.begin(), path.end());

    return path;
}

/*========================================================
12. DIJKSTRA
Use:
- weighted graph
- no negative weights
DS used:
- min heap / priority_queue
- dist[]
- optional parent[]
========================================================*/
vector<int> dijkstra(int V, vector<vector<pair<int,int>>>& adj, int src) {
    vector<int> dist(V, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    // {distance, node}

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        if (d > dist[node]) continue;

        for (auto [neigh, wt] : adj[node]) {
            if (dist[neigh] > d + wt) {
                dist[neigh] = d + wt;
                pq.push({dist[neigh], neigh});
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (dist[i] == INF) dist[i] = -1;
    }
    return dist;
}

/*========================================================
13. DIJKSTRA + PATH RECONSTRUCTION
DS used:
- min heap
- dist[]
- parent[]
========================================================*/
vector<int> dijkstraPath(int V, vector<vector<pair<int,int>>>& adj, int src, int dest) {
    vector<int> dist(V, INF), parent(V);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    for (int i = 0; i < V; i++) parent[i] = i;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        if (d > dist[node]) continue;

        for (auto [neigh, wt] : adj[node]) {
            if (dist[neigh] > d + wt) {
                dist[neigh] = d + wt;
                parent[neigh] = node;
                pq.push({dist[neigh], neigh});
            }
        }
    }

    if (dist[dest] == INF) return {};

    vector<int> path;
    int cur = dest;
    while (parent[cur] != cur) {
        path.push_back(cur);
        cur = parent[cur];
    }
    path.push_back(src);
    reverse(path.begin(), path.end());

    return path;
}

/*========================================================
14. DAG SHORTEST PATH (TOPO + RELAX)
Use:
- shortest path in DAG
- better than Dijkstra for DAG
DS used:
- weighted adjacency list
- stack / topo order
- dist[]
Key idea:
- process nodes in topological order
========================================================*/
void topoDFSWeighted(int node, vector<vector<pair<int,int>>>& adj, vector<int>& vis, stack<int>& st) {
    vis[node] = 1;
    for (auto [neigh, wt] : adj[node]) {
        if (!vis[neigh]) topoDFSWeighted(neigh, adj, vis, st);
    }
    st.push(node);
}

vector<int> shortestPathDAG(int V, vector<vector<pair<int,int>>>& adj, int src) {
    vector<int> vis(V, 0);
    stack<int> st;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) topoDFSWeighted(i, adj, vis, st);
    }

    vector<int> dist(V, INF);
    dist[src] = 0;

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (dist[node] == INF) continue;

        for (auto [neigh, wt] : adj[node]) {
            if (dist[neigh] > dist[node] + wt) {
                dist[neigh] = dist[node] + wt;
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (dist[i] == INF) dist[i] = -1;
    }
    return dist;
}

/*========================================================
15. BELLMAN-FORD
Use:
- negative weights allowed
- detect negative cycle
DS used:
- edge list
- dist[]
========================================================*/
pair<vector<int>, bool> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int> dist(V, INF);
    dist[src] = 0;

    // Relax edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (auto& e : edges) {
            int u = e[0], v = e[1], wt = e[2];
            if (dist[u] != INF && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check negative cycle
    bool hasNegativeCycle = false;
    for (auto& e : edges) {
        int u = e[0], v = e[1], wt = e[2];
        if (dist[u] != INF && dist[u] + wt < dist[v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    for (int i = 0; i < V; i++) {
        if (dist[i] == INF) dist[i] = -1;
    }

    return {dist, hasNegativeCycle};
}

/*========================================================
16. BIPARTITE GRAPH CHECK (BFS)
Use:
- 2-coloring
- odd cycle detection
DS used:
- queue
- color[] initialized with -1
========================================================*/
bool isBipartiteBFS(int V, vector<vector<int>>& adj) {
    vector<int> color(V, -1);

    for (int i = 0; i < V; i++) {
        if (color[i] != -1) continue;

        queue<int> q;
        q.push(i);
        color[i] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neigh : adj[node]) {
                if (color[neigh] == -1) {
                    color[neigh] = 1 - color[node];
                    q.push(neigh);
                } else if (color[neigh] == color[node]) {
                    return false;
                }
            }
        }
    }
    return true;
}

/*========================================================
17. BIPARTITE GRAPH CHECK (DFS)
========================================================*/
bool dfsBipartite(int node, int col, vector<vector<int>>& adj, vector<int>& color) {
    color[node] = col;

    for (int neigh : adj[node]) {
        if (color[neigh] == -1) {
            if (!dfsBipartite(neigh, 1 - col, adj, color)) return false;
        } else if (color[neigh] == color[node]) {
            return false;
        }
    }
    return true;
}

bool isBipartiteDFS(int V, vector<vector<int>>& adj) {
    vector<int> color(V, -1);

    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            if (!dfsBipartite(i, 0, adj, color)) return false;
        }
    }
    return true;
}

/*========================================================
18. DISJOINT SET UNION (UNION-FIND)
Use:
- dynamic connectivity
- Kruskal MST
- detect cycle in undirected graph (edge list style)
DS used:
- parent[]
- size[] or rank[]
========================================================*/
class DSU {
public:
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv) return;

        if (sz[pu] < sz[pv]) swap(pu, pv);
        parent[pv] = pu;
        sz[pu] += sz[pv];
    }
};

/*========================================================
19. KRUSKAL'S MST
Use:
- minimum spanning tree in undirected weighted graph
DS used:
- DSU
- sorted edges
Edge format: {weight, u, v}
========================================================*/
int kruskalMST(int V, vector<vector<int>>& edges) {
    sort(edges.begin(), edges.end()); // sort by weight
    DSU dsu(V);

    int mstWeight = 0;

    for (auto& e : edges) {
        int wt = e[0], u = e[1], v = e[2];

        if (dsu.findUPar(u) != dsu.findUPar(v)) {
            mstWeight += wt;
            dsu.unionBySize(u, v);
        }
    }

    return mstWeight;
}

/*========================================================
20. PRIM'S MST
Use:
- minimum spanning tree
DS used:
- min heap
- visited[]
========================================================*/
int primMST(int V, vector<vector<pair<int,int>>>& adj) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> vis(V, 0);

    // {weight, node}
    pq.push({0, 0});
    int mstWeight = 0;

    while (!pq.empty()) {
        auto [wt, node] = pq.top();
        pq.pop();

        if (vis[node]) continue;
        vis[node] = 1;
        mstWeight += wt;

        for (auto [neigh, edgeWt] : adj[node]) {
            if (!vis[neigh]) {
                pq.push({edgeWt, neigh});
            }
        }
    }

    return mstWeight;
}

/*========================================================
21. NUMBER OF ISLANDS (GRID DFS)
Use:
- count connected components in 2D grid
DS used:
- grid visited
- recursion
========================================================*/
void dfsIsland(int r, int c, vector<vector<char>>& grid, vector<vector<int>>& vis,
               int dr[], int dc[]) {
    int n = grid.size(), m = grid[0].size();
    vis[r][c] = 1;

    for (int k = 0; k < 4; k++) {
        int nr = r + dr[k];
        int nc = c + dc[k];

        if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
            !vis[nr][nc] && grid[nr][nc] == '1') {
            dfsIsland(nr, nc, grid, vis, dr, dc);
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && grid[i][j] == '1') {
                cnt++;
                dfsIsland(i, j, grid, vis, dr, dc);
            }
        }
    }
    return cnt;
}

/*========================================================
22. SHORTEST PATH IN BINARY MATRIX / GRID (BFS)
Use:
- minimum steps in grid
- each move has equal weight
DS used:
- queue
- dist[] or visited
========================================================*/
int shortestPathGrid(vector<vector<int>>& grid, pair<int,int> src, pair<int,int> dest) {
    int n = grid.size(), m = grid[0].size();
    if (grid[src.first][src.second] == 0 || grid[dest.first][dest.second] == 0) return -1;

    vector<vector<int>> dist(n, vector<int>(m, INF));
    queue<pair<int,int>> q;

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    dist[src.first][src.second] = 0;
    q.push(src);

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                grid[nr][nc] == 1 && dist[nr][nc] > dist[r][c] + 1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    return dist[dest.first][dest.second] == INF ? -1 : dist[dest.first][dest.second];
}

/*========================================================
23. FLOOD FILL (DFS)
Use:
- recolor connected region
DS used:
- recursion
========================================================*/
void dfsFlood(int r, int c, vector<vector<int>>& image, int oldColor, int newColor,
              vector<vector<int>>& ans, int dr[], int dc[]) {
    int n = image.size(), m = image[0].size();
    ans[r][c] = newColor;

    for (int k = 0; k < 4; k++) {
        int nr = r + dr[k];
        int nc = c + dc[k];

        if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
            ans[nr][nc] != newColor && image[nr][nc] == oldColor) {
            dfsFlood(nr, nc, image, oldColor, newColor, ans, dr, dc);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int oldColor = image[sr][sc];
    vector<vector<int>> ans = image;

    if (oldColor == newColor) return ans;

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    dfsFlood(sr, sc, image, oldColor, newColor, ans, dr, dc);
    return ans;
}

/*========================================================
24. COMMON BUILD HELPERS
========================================================*/
vector<vector<int>> buildAdjUnweightedDirected(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    for (auto& e : edges) {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
    }
    return adj;
}

vector<vector<int>> buildAdjUnweightedUndirected(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    for (auto& e : edges) {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}

vector<vector<pair<int,int>>> buildAdjWeightedDirected(int V, vector<vector<int>>& edges) {
    vector<vector<pair<int,int>>> adj(V);
    for (auto& e : edges) {
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});
    }
    return adj;
}

vector<vector<pair<int,int>>> buildAdjWeightedUndirected(int V, vector<vector<int>>& edges) {
    vector<vector<pair<int,int>>> adj(V);
    for (auto& e : edges) {
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    return adj;
}

/*========================================================
25. OPTIONAL MAIN FOR TESTING
Uncomment if needed.
========================================================*/
/*
int main() {
    int V = 5;
    vector<vector<int>> edges = {{0,1}, {1,2}, {2,3}, {3,4}};
    auto adj = buildAdjUnweightedUndirected(V, edges);

    vector<int> bfs = bfsTraversal(V, adj, 0);
    for (int x : bfs) cout << x << " ";
    cout << "\n";

    return 0;
}
*/
