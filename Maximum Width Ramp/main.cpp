class Solution {
    public:
        int maxWidthRamp(vector<int>& nums) {
            int n = nums.size();
            vector<int> rMax(n);

            rMax[n - 1] = nums[n - 1];

            for(int i = n - 2; i >= 0; i--) {
                rMax[i] = max(rMax[i + 1], nums[i]);
            }

            int l = 0;
            int r = 0;
            int maxi = 0;

            while(r < n) {
                while(r < n && nums[l] <= rMax[r])
                    r++;

                maxi = max(maxi, r - l - 1);
                l++;
                r = l + maxi + 1;
            }
            return maxi;
        }
};