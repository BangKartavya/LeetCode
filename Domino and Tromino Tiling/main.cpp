class Solution {
    private:
        const int MOD = 1e9 + 7;

    public:
        int numTilings(int n) {
            vector<long long> dp(n + 1);

            for(int i = 0; i <= n; i++) {
                if(i <= 2) {
                    dp[i] = i;
                } else if(i == 3) {
                    dp[i] = 2 * dp[i - 1] + 1;
                } else {
                    dp[i] = ((2 * dp[i - 1] % MOD) % MOD + dp[i - 3] % MOD) % MOD;
                }
            }

            return dp[n] % MOD;
        }
};