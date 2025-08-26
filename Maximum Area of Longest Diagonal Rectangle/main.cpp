class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxi = 0;
        double maxDiag = 0;

        for(vector<int>& v: dimensions) {
            int l = v[0];
            int w = v[1];

            double diag = sqrt(l*l + w*w);

            if(diag > maxDiag) {
                maxDiag = diag;
                maxi = l*w;
            }

            if(diag == maxDiag) {
                maxi = max(maxi,l*w);
            }
        }

        return maxi;

    }
};