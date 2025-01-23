class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();
        
        int cnt = 0;
        vector<int> r(m);
        vector<int> c(n);
    
        for(int i = 0 ;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(grid[i][j]) {
                    cnt++;
                    r[i]++;
                    c[j]++;
                }
            }
        }

        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(grid[i][j] && r[i] == 1 && c[j] == 1) cnt--;
            }
        }

        return cnt;

    }
};