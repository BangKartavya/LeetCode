class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int result = 0;
        vector<vector<int>> dp(m,vector<int>(n));

        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(j == 0) dp[i][j] = mat[i][j];
                else {
                    if(mat[i][j] == 0) dp[i][j] = 0;
                    else {
                        dp[i][j] = 1 + dp[i][j-1];
                    }
                }
            }
        }

        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                int mini = dp[i][j];

                for(int k = i;k>=0;k--) {
                    mini = min(mini,dp[k][j]);

                    if(mini == 0) break;
                    result += mini;
                }

            }
        }

        return result;
    }
};