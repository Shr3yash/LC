class Solution {
public:
    int adjacentTraversal(int x, int y, vector<vector<int>>& grid,
                          vector<vector<bool>>& visited) {
        // Check for out-of-bounds or invalid conditions
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() ||
            visited[x][y] || grid[x][y] == 0) {
            return 0;
        }

        // Mark the current cell as visited
        visited[x][y] = true;

        // Collect fish from the current cell and recursively explore adjacent
        // cells
        int totalFishes = grid[x][y];
        totalFishes += adjacentTraversal(x, y + 1, grid, visited); // Right
        totalFishes += adjacentTraversal(x, y - 1, grid, visited); // Left
        totalFishes += adjacentTraversal(x + 1, y, grid, visited); // Down
        totalFishes += adjacentTraversal(x - 1, y, grid, visited); // Up

        return totalFishes;
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0)
            return 0; // Handle empty grid
        int m = grid[0].size();

        // Initialize visited grid with the same size as grid, filled with false
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int ans = 0;

        // Iterate through each cell in the grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // If the cell is unvisited and contains fish, start DFS
                if (!visited[i][j] && grid[i][j] != 0) {
                    int localMax = adjacentTraversal(i, j, grid, visited);
                    ans = max(localMax, ans);
                }
            }
        }

        return ans;
    }
};