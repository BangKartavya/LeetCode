class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0) return 0;

        int n = nums.size();
        int product = 1;
        int cnt = 0;

        int l = 0;
        int r = 0;
        while(r<n) {
            product*=nums[r++];
            while(l<r && product>=k) product/=nums[l++];
            cnt+=(r-l);
        }
        return cnt;
    }
};