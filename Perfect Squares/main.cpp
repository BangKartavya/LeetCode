class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int i =1;i<=n;++i) {
            int min_val = INT_MAX;
            for(int j = 1;j*j<=i;++j) {
                min_val = min(min_val,dp[i-j*j]+1);
            }
            dp[i] = min_val;
        }
        return dp[n];
    }
};