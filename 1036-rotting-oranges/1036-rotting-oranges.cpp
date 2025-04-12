class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
      int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Initialize the queue with all initially rotten oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    visited[i][j] = 2;
                    q.push({{i, j}, 0});
                }
            }
        }

        int timer = 0;
        int row_d[] = {-1, 0, 1, 0};
        int col_d[] = {0, 1, 0, -1};

        // BFS to spread the rot to adjacent fresh oranges
        while (!q.empty()) {
            int row_v = q.front().first.first;
            int col_v = q.front().first.second;
            int t = q.front().second;
            timer = max(timer, t);
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row_v + row_d[i];
                int ncol = col_v + col_d[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    visited[nrow][ncol] = 2;
                }
            }
        }

        // Check if there are any fresh oranges left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] != 2 && grid[i][j] == 1) return -1;
            }
        }

        return timer;
    }
};