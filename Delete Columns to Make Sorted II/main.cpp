class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        vector<bool> resolved(n,false);
        int unresolved = n-1;
        int res = 0;

        for(int j = 0;j<m && unresolved > 0;j++) {
            bool isSorted = true;
            for(int i = 0;i<n-1;i++) {
                if(!resolved[i] && strs[i][j] > strs[i+1][j]) {
                    isSorted = false;
                    break;
                }
            }
            res += (!isSorted);
            
            if(isSorted) {
                for(int i = 0;i<n-1;i++) {
                    if(!resolved[i] && strs[i][j] < strs[i+1][j]) {
                        resolved[i] = true;
                        unresolved--;
                    }
                }
            }
        }

        return res;
    }
};