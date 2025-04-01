class Solution {
private:
    vector<vector<int>> questions;
    int n;

    vector<long long> dp;

    long long solve(int i) {
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        long long take = questions[i][0] + solve(i+questions[i][1]+1);
        long long noTake = solve(i+1);

        return dp[i] = max(take,noTake);
    }

public:
    long long mostPoints(vector<vector<int>>& questions) {
        this->questions = questions;
        n = questions.size();
        dp.resize(n+1,-1);
        return solve(0);
    }
};