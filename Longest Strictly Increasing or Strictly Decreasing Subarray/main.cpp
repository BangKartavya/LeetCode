class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxi = 1;
        int n = nums.size();

        int incLen = 1;
        int decLen = 1;

        for(int i = 0;i<n-1;i++) {
            if(nums[i] < nums[i+1]) {
                incLen++;
                decLen = 1;
            }
            else if(nums[i] > nums[i+1]) {
                decLen++;
                incLen = 1;
            }
            else {
                decLen = 1;
                incLen = 1;
            }

            maxi = max({maxi,incLen,decLen});
        }

        return maxi;
        
    }
};