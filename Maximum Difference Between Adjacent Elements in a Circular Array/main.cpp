class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();

        for(int i = 0;i<n;i++) {
            maxi = max(maxi,abs(nums[i]-nums[(i+1)%n]));
        }

        return maxi;
    }
};