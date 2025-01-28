class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        /*
            land = 0
            fish > 0 
        */
        int m = grid.size();
        int n = grid[0].size();

        int dirX[4] = {0,-1,0,1};
        int dirY[4] = {1,0,-1,0};

        int result = 0;

        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(grid[i][j] == 0) continue;
                // src -> (i,j)
                vector<vector<bool>> vis(m,vector<bool>(n,false));

                queue<pair<int,int>> q;

                q.push({i,j});
                vis[i][j] = true;

                int totalCaught = 0;

                while(!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    totalCaught += grid[x][y];

                    for(int k = 0;k<4;k++) {
                        int newX = x + dirX[k];
                        int newY = y + dirY[k];

                        if(newX < 0 || newX >= m || newY < 0 || newY >= n) continue;

                        if(grid[newX][newY] != 0 && !vis[newX][newY]) { 
                            q.push({newX,newY});
                            vis[newX][newY] = true;
                        }
                    }
                }

                if(totalCaught == 12) {
                    cout << "x : " << i << endl;
                    cout << "y : " << j << endl;
                }

                result = max(result,totalCaught);

            }
        }
            return result;
    }
};