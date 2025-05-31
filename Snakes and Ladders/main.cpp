class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), label = 1;
        vector<pair<int, int>> cells(n * n + 1);
        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0);

        for (int row = n - 1; row >= 0; row--) {
            for (int col : columns) {
                cells[label++] = {row, col};
            }
            reverse(columns.begin(), columns.end());  // zigzag pattern
        }

        vector<int> dist(n * n + 1, -1);
        dist[1] = 0;
        queue<int> q;
        q.push(1);

        while (!q.empty()) {
            int curr = q.front(); q.pop();
            for (int move = 1; move <= 6 && curr + move <= n * n; move++) {
                auto [r, c] = cells[curr + move];
                int dest = board[r][c] == -1 ? curr + move : board[r][c];
                if (dist[dest] == -1) {
                    dist[dest] = dist[curr] + 1;
                    q.push(dest);
                }
            }
        }

        return dist[n * n];
    }
};