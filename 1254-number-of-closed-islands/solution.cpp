#include <vector>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>>& grid, int r, int c, int m, int n) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != 0) {
            return;
        }
        grid[r][c] = 1; // Mark as visited / water
        dfs(grid, r + 1, c, m, n);
        dfs(grid, r - 1, c, m, n);
        dfs(grid, r, c + 1, m, n);
        dfs(grid, r, c - 1, m, n);
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Flood fill lands connected to the boundary
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 0) dfs(grid, i, 0, m, n);
            if (grid[i][n - 1] == 0) dfs(grid, i, n - 1, m, n);
        }
        for (int j = 0; j < n; ++j) {
            if (grid[0][j] == 0) dfs(grid, 0, j, m, n);
            if (grid[m - 1][j] == 0) dfs(grid, m - 1, j, m, n);
        }

        int closedIslands = 0;
        // Count remaining closed islands
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                if (grid[i][j] == 0) {
                    ++closedIslands;
                    dfs(grid, i, j, m, n);
                }
            }
        }

        return closedIslands;
    }
};
