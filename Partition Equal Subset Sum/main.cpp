class Solution {
private:
    vector<int> nums;
    int n;
    int target;

    vector<vector<int>> dp;

    bool solve(int i, int curr) {
        if(i >= n) {
            return target == curr;
        }

        if(target == curr) return true;

        if(curr > target) return false;

        if(dp[i][curr] != -1) return dp[i][curr];

        bool take = solve(i+1,curr+nums[i]);
        bool noTake = solve(i+1,curr);

        return dp[i][curr] = take || noTake;
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(begin(nums),end(nums),0);
        if(sum%2 != 0) return false;
        this->nums = nums;
        n = nums.size();
        target = sum/2;
        dp.resize(n+1,vector<int>(target+1,-1));
        return solve(0,0);
    }
};