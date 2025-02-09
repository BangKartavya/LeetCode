class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,long long> mp;

        long long goodPairs = 0;
        long long totalPairs = 0;

        for(int i = 0;i<n;i++) {
            if(mp.count(nums[i]-i) > 0) {
                goodPairs += mp[nums[i]-i];
            }
            mp[nums[i]-i]++;
            totalPairs += i;
        }


        return totalPairs - goodPairs;
    }
};