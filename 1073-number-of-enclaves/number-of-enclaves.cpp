
class Solution {
public:
    int m, n;

    void dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= m || j >= n ||
            grid[i][j] == 0) {
            return;
        }

        grid[i][j] = 0;  // Mark visited

        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Remove land connected to the boundary
        for (int i = 0; i < m; i++) {
            dfs(i, 0, grid);
            dfs(i, n - 1, grid);
        }

        for (int j = 0; j < n; j++) {
            dfs(0, j, grid);
            dfs(m - 1, j, grid);
        }

        // Count remaining land cells
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};
