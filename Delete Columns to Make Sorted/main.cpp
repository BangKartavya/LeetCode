class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        int res = 0;

        for(int j = 0;j<m;j++) {
            bool isSorted = true;
            for(int i = 0;i<n-1;i++) {
                if(strs[i][j] > strs[i+1][j]) {
                    isSorted = false;
                    break;
                }
            }

            res += (!isSorted);
        }

        return res;
    }
};