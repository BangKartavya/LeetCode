class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int m = queries.size();

        vector<int> pref(n);
        vector<int> ans;

        pref[0] = arr[0];

        for(int i = 1;i<n;i++) pref[i] = pref[i-1]^arr[i];

        for(auto q: queries) {
            int i = q[0];
            int j = q[1];

            if(i == 0) ans.push_back(pref[j]);
            else ans.push_back(pref[j]^pref[i-1]);
        }
        return ans;
    }
};