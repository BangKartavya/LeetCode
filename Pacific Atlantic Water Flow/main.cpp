class Solution {
    public:
        vector<vector<int>> pacificAtlantic(vector<vector<int>>& height) {
            int m = height.size();
            int n = height[0].size();

            int dirX[4] = {0, -1, 0, 1};
            int dirY[4] = {1, 0, -1, 0};

            queue<pair<int, int>> q; // {x,y}
            vector<vector<bool>> visPas(m, vector<bool>(n, false));

            for(int j = 0; j < n; j++) {
                q.push({0, j});
                visPas[0][j] = true;
            }

            for(int i = 0; i < m; i++) {
                q.push({i, 0});
                visPas[i][0] = true;
            }

            while(!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int newX = x + dirX[i];
                    int newY = y + dirY[i];

                    if(newX < 0 || newX >= m || newY < 0 || newY >= n) continue;

                    if(!visPas[newX][newY] && height[x][y] <= height[newX][newY]) {
                        visPas[newX][newY] = true;
                        q.push({newX, newY});
                    }
                }
            }

            vector<vector<bool>> visAtl(m, vector<bool>(n, false));

            for(int j = 0; j < n; j++) {
                q.push({m - 1, j});
                visAtl[m - 1][j] = true;
            }
            for(int i = 0; i < m; i++) {
                q.push({i, n - 1});
                visAtl[i][n - 1] = true;
            }

            while(!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int newX = x + dirX[i];
                    int newY = y + dirY[i];

                    if(newX < 0 || newX >= m || newY < 0 || newY >= n) continue;

                    if(!visAtl[newX][newY] && height[x][y] <= height[newX][newY]) {
                        visAtl[newX][newY] = true;
                        q.push({newX, newY});
                    }
                }
            }

            vector<vector<int>> result;

            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(visPas[i][j] && visAtl[i][j]) result.push_back({i, j});
                }
            }

            return result;
        }
};