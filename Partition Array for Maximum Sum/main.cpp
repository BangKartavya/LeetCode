class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);

        for(int i =0;i<n;i++) {
            int curMax = 0;
            int curSum = 0;

            for(int j = i;j>=max(0,i-k+1);j--) {
                curMax = max(curMax,arr[j]);
                int cur = curMax * (i-j+1)+dp[j];
                curSum = max(curSum,cur);
            }
            dp[i+1] = curSum;
        }

        return dp[n];
    }
};