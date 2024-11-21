class Solution {
    public:
        int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
            vector<vector<int>> grid(m, vector<int>(n, 0));

            for(auto i : guards) {
                grid[i[0]][i[1]] = 2;
            }
            for(auto i : walls) {
                grid[i[0]][i[1]] = 2;
            }

            int dx[4] = {0, 0, -1, 1};
            int dy[4] = {-1, 1, 0, 0};

            for(auto i : guards) {
                for(int k = 0; k < 4; k++) {
                    int x = i[0];
                    int y = i[1];
                    int dirX = dx[k];
                    int dirY = dy[k];

                    while(x + dirX >= 0 && x + dirX < m && y + dirY >= 0 && y + dirY < n && grid[x + dirX][y + dirY] < 2) {
                        x += dirX;
                        y += dirY;
                        grid[x][y] = 1;
                    }
                }
            }
            int cnt = 0;
            for(auto i : grid) {
                for(auto j : i)
                    if(j == 0) cnt++;
            }

            return cnt;
        }
};