class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs[0].size();

        vector<int> dp(m,1);

        for(int i = 0;i<m;i++) {
            for(int j = 0;j<i;j++) {
                bool isValid = true;
                for(string& row : strs) {
                    if(row[j] > row[i]) {
                        isValid = false;
                        break;
                    }
                }
                if(isValid) {
                    dp[i] = max(dp[i], dp[j]+1);
                }

            }
        }
        return m - *max_element(begin(dp),end(dp));
    }
};