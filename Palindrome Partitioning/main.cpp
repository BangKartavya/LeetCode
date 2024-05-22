class Solution {
public:
    int n;
    vector<vector<int>> dp;

    //judge whether s[l..r] is palindrome storing into dp[l][r]
    inline bool isPalindrome(string& s, int l, int r){
        if (dp[l][r] != -1){
            return dp[l][r]==1;
        }  
        while (l < r){
            if (s[l] != s[r]) 
                return dp[l][r] = 0;     
            l++;
            r--;       
        }
        return dp[l][r] = 1;
    }

    // backtracking to find the valid partitions for s[start:]
    vector<vector<string>> ans;
    inline void dfs(string &s, int start, vector<string>& valids) {
        if (start >= n)
            ans.push_back(valids);
        for (int end = start; end < n; end++) {
            if (isPalindrome(s, start, end)) {
                valids.push_back(s.substr(start, end - start + 1));
                dfs(s, end+1, valids);
                valids.pop_back();//backtracking
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.size();
        if (n == 1) return {{s}};
        dp.assign(n, vector<int>(n, -1));
        vector<string> valids;
        dfs(s, 0, valids);
        return ans;
    }
};