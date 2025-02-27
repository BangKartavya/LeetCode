class Solution {
    private:
        vector<int> arr;
        int n;
        unordered_map<int, int> mp;
        vector<vector<int>> dp;

        int solve(int i, int j) {
            if(i >= n || j >= n) return 0;

            if(dp[i][j] != -1) return dp[i][j];

            int next = arr[i] + arr[j];

            if(mp.find(next) == mp.end()) return 0;

            return dp[i][j] = 1 + solve(j, mp[next]);
        }

    public:
        int lenLongestFibSubseq(vector<int>& arr) {
            this->arr = arr;
            n = arr.size();

            for(int i = 0; i < n; i++)
                mp[arr[i]] = i;

            dp.resize(n + 1, vector<int>(n + 1, -1));
            int maxi = 0;

            for(int i = 0; i < n; i++) {
                for(int j = i + 1; j < n; j++) {
                    maxi = max(maxi, 2 + solve(i, j));
                }
            }

            return maxi == 2 ? 0 : maxi;
        }
};