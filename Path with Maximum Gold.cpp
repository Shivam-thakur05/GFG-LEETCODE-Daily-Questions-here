class Solution {
public:
    int DFS(vector<vector<int>>& grid, int i, int j,int m,int n) {
        if (i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == 0) {
            return 0;
        }
        int originalValue = grid[i][j];
        grid[i][j] = 0;
        int maxGold = originalValue; // Initialize maxGold with current cell value

        // Calculate maximum gold obtained by exploring all four directions
        maxGold += max(DFS(grid, i - 1, j,m,n), max(DFS(grid, i + 1, j,m,n), max(DFS(grid, i, j - 1,m,n), DFS(grid, i, j + 1,m,n))));

        grid[i][j] = originalValue;

        return maxGold;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();

        int maxGold = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    // It has gold
                    maxGold = max(maxGold, DFS(grid, i, j,m,n));
                }
            }
        }
        return maxGold;
    }
};
