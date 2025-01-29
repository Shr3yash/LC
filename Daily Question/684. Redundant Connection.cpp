class Solution {
private:
    // Performs DFS to check if 'src' and 'target' are already connected.
    bool isConnected(int src, int target, vector<bool>& visited, vector<int> adjList[]) {
        visited[src] = true; // Mark current node as visited

        // Base case: Found the target node
        if (src == target) return true;

        bool isFound = false;
        // Explore all adjacent nodes
        for (int adj : adjList[src]) {
            if (!visited[adj]) {
                // Recursively check if path exists from 'adj' to 'target'
                isFound = isFound || isConnected(adj, target, visited, adjList);
            }
        }
        return isFound;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();

        // Adjacency list to represent the graph (0-based indexing)
        vector<int> adjList[N];

        for (auto edge : edges) {
            // Convert edge to 0-based indices (e.g., [1,2] → [0,1])
            int u = edge[0] - 1, v = edge[1] - 1;

            // Check if 'u' and 'v' are already connected (cycle detection)
            vector<bool> visited(N, false);
            if (isConnected(u, v, visited, adjList)) {
                // Cycle detected! Return this edge as redundant
                return edge;
            }

            // Add the edge to the graph (no cycle yet)
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        return {}; // No redundant edge found (should not happen as per the statement)
    }
};