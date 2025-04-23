class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> s;
        for(int& i: nums) s.insert(i);

        unordered_map<int,int> mp;

        int l = 0;
        int r = 0;
        int n = nums.size();
        int ans = 0;

        while(r < n) {
            mp[nums[r]]++;

            if(mp.size() == s.size()) {
                while(mp.size() == s.size() && l <= r) {
                    mp[nums[l]]--;
                    if(mp[nums[l]] == 0) mp.erase(nums[l]);
                    ans += (n-r);
                    l++;
                }

            }

            r++;
        }

        return ans;
    }
};