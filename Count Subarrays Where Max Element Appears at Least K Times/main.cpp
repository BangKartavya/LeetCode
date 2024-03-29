class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_elem = *max_element(nums.begin(),nums.end());

        long long int size = 0;
        long long int ans = 0;
    
        for(int s=0,e=0;e<nums.size();e++) {
            size += (nums[e]==max_elem);
            while(size>=k) size-=(nums[s++]==max_elem);
            ans += s;
        }
        return ans;
    }
};