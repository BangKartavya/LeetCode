class Solution {
private:
    vector<vector<int>> grid;
    int m;
    int n;
    int k;
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    int solve(int i, int j, int sum) {
        if(i >= m || j >= n) return 0;
        if(i == m-1 && j == n-1) {
            if((sum + grid[i][j]) % k == 0) return 1;
            return 0;
        }

        if(dp[i][j][sum] != -1) return dp[i][j][sum];

        int down = solve(i+1,j,(sum+grid[i][j]) % k);
        int right = solve(i,j+1,(sum + grid[i][j]) % k);

        return dp[i][j][sum] = (down % MOD + right % MOD) % MOD;
    }

public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();
        this->k = k;
        dp.resize(m,vector<vector<int>>(n,vector<int>(k,-1)));
        return solve(0,0,0);   
    }
};