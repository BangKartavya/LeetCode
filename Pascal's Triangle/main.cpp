class Solution {
private:
    unordered_map<int,vector<int>> dp;

    vector<int> generateRow(int numRows) {
        if(numRows == 1) return {1};
        if(numRows == 2) return {1,1};

        if(dp.find(numRows) != dp.end()) return dp[numRows];

        vector<int> prevRow = generateRow(numRows-1);

        vector<int> currRow(prevRow.size()+1);
        currRow[0] = 1;
        currRow.back() = 1;

        for(int i = 1;i<prevRow.size();i++) {
            currRow[i] = prevRow[i-1] + prevRow[i];
        }
        return dp[numRows] = currRow;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i = 1;i<=numRows;i++) {
            result.push_back(generateRow(i));
        }

        return result;
    }
};