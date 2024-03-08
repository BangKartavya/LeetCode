class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(auto i: nums) mp[i]++;

        int ans = 0;
        int maxi = INT_MIN;

        for(auto it: mp) {
            maxi = max(maxi,it.second);
        }

        for(auto it: mp) {
            if(it.second==maxi) ans+=it.second;
        }
        return ans;
    }
};