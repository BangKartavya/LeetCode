#include <queue>
#include <utility>
#include <vector>

class Solution {
private:
    std::vector<std::vector<int>> cells;
    int row;
    int col;

    int dir[5] = {0,-1,0,1,0};

    bool isValid(std::vector<std::vector<int>> grid, int maxDays) {

        for(int i = 0;i<maxDays;i++) {
            grid[cells[i][0]-1][cells[i][1]-1]=1;
        }

        std::queue<std::pair<int,int>> q; // {x,y}
        std::vector<std::vector<bool>> vis(row,std::vector<bool>(col,false));

        for(int i = 0;i<col;i++) {
            if(grid[0][i] == 0) {
                q.push({0,i});
                vis[0][i] = true;
            }
        }

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x == row-1) return true;

            for(int i = 0;i<4;i++) {
                int newX = x + dir[i];
                int newY = y + dir[i+1];

                if(newX < 0 || newX >= row || newY < 0 || newY >= col) continue;

                if(!grid[newX][newY] && !vis[newX][newY]) {
                    q.push({newX,newY});
                    vis[newX][newY] = true;
                }
            }
        }

        return false;

    }
public:
    int latestDayToCross(int row, int col, std::vector<std::vector<int>>& cells) {
        std::vector<std::vector<int>> grid(row,std::vector<int>(col,0));
        this->cells = cells;
        this->row = row;
        this->col = col;

        int s = 0;
        int e = row*col-1;
        int ans = 0;

        while(s <= e) {
            int mid = s + (e-s) / 2;

            if(isValid(grid,mid)) {
                s = mid+1;
                ans = mid;
            }
            else e = mid-1;
        }
        return ans;
    }
};
