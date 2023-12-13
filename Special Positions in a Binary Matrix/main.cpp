class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> rCount(mat.size(),0);
        vector<int> cCount(mat[0].size(),0);

        for(int i =0;i<mat.size();i++) {
            for(int j =0;j<mat[i].size();j++) {
                if(mat[i][j]==1) {
                    rCount[i]++;
                    cCount[j]++;
                }
            }
        }

        int ans = 0;
        for(int i =0;i<mat.size();i++) {
            for(int j =0;j<mat[i].size();j++) {
                if(mat[i][j]==1) {
                    if(rCount[i]==1 && cCount[j]==1) ans++;
                }
            }
        }
        return ans;
    }
};