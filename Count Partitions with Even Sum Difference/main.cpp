class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(begin(nums),end(nums),0);

        int ans = 0;
        int left = 0;

        for(int i = 0;i<n-1;i++) {
            left += nums[i];
            sum -= nums[i];
            ans += ((left - sum) % 2 == 0);
        }

        return ans;
    }
};