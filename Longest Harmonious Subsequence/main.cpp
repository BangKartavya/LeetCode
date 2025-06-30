class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int& i: nums) mp[i]++;

        int ans = 0;

        for(int& i: nums) {
            if(mp.find(i+1) != mp.end()) {
                ans = max(ans,mp[i+1]+mp[i]);
            }
            if(mp.find(i-1) != mp.end()) {
                ans = max(ans,mp[i-1]+mp[i]);
            }
        }

        return ans;
    }
};