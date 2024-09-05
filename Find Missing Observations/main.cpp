class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total = mean* (n+m);
        int obs = accumulate(begin(rolls),end(rolls),0);
        int missing = total - obs;

        if(missing < n || missing > 6*n) return {};

        vector<int> ans(n);

        int quo = missing / n;
        int rem = missing % n;

        for(int i =0;i<n;i++) {
            ans[i] = quo;
        }
        for(int i =0;i<rem;i++) {
            ans[i]++;
        }
        return ans;

    }
};