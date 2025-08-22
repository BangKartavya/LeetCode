class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int fr = INT_MAX;
        int fc = INT_MAX;
        int lr = -1;
        int lc = -1;

        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j] == 1) {
                    fr = min(i,fr);
                    fc = min(j,fc);
                    lr = max(i,lr);
                    lc = max(j,lc);
                }
            }
        }

        return (lr-fr+1) * (lc-fc+1);
    }
};