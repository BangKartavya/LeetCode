class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        
        for(int i =0;i<m;i++) {
            for(int j =0;j<n;j++) {
                int total_sum = 0;
                int count = 0;
                
                for(int x = max(0,i-1);x<min(m,i+2);++x) {
                    for(int y = max(0,j-1);y<min(n,j+2);++y) {
                        total_sum += img[x][y];
                        count++;
                    }
                }
                ans[i][j] = total_sum/count;
            }
        }
        return ans;
    }
};