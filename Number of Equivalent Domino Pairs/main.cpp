class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        int cnt = 0;

        map<vector<int>,int> mp;

        for(int i = 0;i<n;i++) {
            vector<int> a = dominoes[i];

            if(mp.find(a) != mp.end()) {
                cnt += mp[a];
            }
            else if(a[0] != a[1] && mp.find({a[1],a[0]}) != mp.end()) {
                cnt += mp[{a[1],a[0]}];
            }

            mp[a]++;
            if(a[0] != a[1]) {
                mp[{a[1],a[0]}]++;
            }
        }

        return cnt;
    }
};