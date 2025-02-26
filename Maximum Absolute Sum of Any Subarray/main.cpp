class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currSum = 0;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int n = nums.size();
        
        for(int i =0 ;i<n;i++) {
            currSum += nums[i];

            if(currSum > maxi) maxi = currSum;
            if(currSum < 0) currSum = 0;
        }
        currSum = 0;
        for(int i =0 ;i<n;i++) {
            currSum += nums[i];

            if(currSum < mini) mini = currSum;
            if(currSum > 0) currSum = 0;
        }

        return max(abs(maxi),abs(mini));
    }
};