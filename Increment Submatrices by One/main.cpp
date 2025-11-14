class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n+1,vector<int>(n+1));

        for(vector<int>& q : queries) {
            int r1 = q[0];
            int c1 = q[1];
            int r2 = q[2];
            int c2 = q[3];

            for(int i = r1;i<=r2;i++) {
                diff[i][c1]++;
                diff[i][c2+1]--;
            }
        }

        for(int j = 1;j<=n;j++) {
            for(int i = 0;i<=n;i++) {
                diff[i][j] += diff[i][j-1];
            }
        }
        diff.pop_back();
        for(int i = 0;i<n;i++) diff[i].pop_back();

        return diff;

    }
};