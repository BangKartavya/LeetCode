class Solution {
    public:
        int triangleNumber(vector<int>& nums) {
            sort(begin(nums), end(nums));
            int n = nums.size();

            int ans = 0;

            for(int i = n - 1; i > 0; i--) {
                int j = 0;
                int k = i - 1;

                if(j == k) continue;
                if(j == i) continue;

                while(j < k) {
                    if(
                        nums[i] + nums[j] > nums[k] &&
                        nums[j] + nums[k] > nums[i] &&
                        nums[k] + nums[i] > nums[j]) {
                        ans += k - j;
                        k--;
                    } else j++;
                }
            }

            return ans;
        }
};