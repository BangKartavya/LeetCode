class Solution {
public:
    int largest(const vector<int>& heights) {
        int res = 0;
        stack<int> stk;

        for(int i =0;i<=heights.size();++i) {
            while(!stk.empty() && (i == heights.size() || heights[stk.top()]>heights[i])) {
                const int m = heights[stk.top()];
                stk.pop();
                const int v = stk.empty() ? i : i-stk.top()-1;
                res = max(res,m*v);
            }
            stk.push(i);
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int res = 0;
        vector<int> hist(matrix[0].size());

        for(const vector<char>& row : matrix) {
            for(int i =0;i<row.size();++i) {
                hist[i] = row[i] == '0' ? 0 : hist[i]+1;
            }
            res = max(res,largest(hist));
        }
        return res;
    }
};