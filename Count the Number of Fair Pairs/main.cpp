class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        
        long long int ans = 0;
        sort(begin(nums),end(nums));
        int n = nums.size();
        
        for(int i = 0;i<n;i++) {
            auto up = upper_bound(begin(nums)+i+1,end(nums),upper-nums[i]);
            auto down = lower_bound(begin(nums)+i+1,end(nums),lower-nums[i]);
            
            ans += (up-down);
        }
        
        return ans;
    }
};