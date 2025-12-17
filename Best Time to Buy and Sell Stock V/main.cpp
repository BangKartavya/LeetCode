class Solution {
private:
    vector<int> prices;
    int n;
    int k;

    vector<vector<vector<long long>>> dp;

    long long solve(int i, int transactionCount, int shortSell) {
        if(i >= n) {
            if(transactionCount <= k && shortSell == 0) return 0;

            return INT_MIN;
        }

        if(transactionCount >= k) return 0;

        if(dp[i][transactionCount][shortSell] != -1) return dp[i][transactionCount][shortSell];      

        long long take = 0;

        if(shortSell == 0) {
            // buy and sell
            // sell and then buy

            take = max(
                -prices[i] + solve(i+1,transactionCount,1),
                prices[i] + solve(i+1,transactionCount,2)
            );
        }
        else if(shortSell == 1) {
            // just sell

            take = prices[i] + solve(i+1,transactionCount+1,0);
        }

        else {
            // just buy
            take = -prices[i] + solve(i+1,transactionCount+1,0);
        }

        long long noTake = solve(i+1,transactionCount,shortSell);


        return dp[i][transactionCount][shortSell] = max(take,noTake);
    }
public:
    long long maximumProfit(vector<int>& prices, int k) {
        this->prices = prices;
        n = prices.size();
        this->k = k;
        dp.resize(n+1,vector<vector<long long>>(k+1,vector<long long>(3,-1)));
        return solve(0,0,0);
    }
};