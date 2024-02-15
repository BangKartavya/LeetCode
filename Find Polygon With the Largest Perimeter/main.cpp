class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long int sum = nums[0]+nums[1];
        long long int res = 0;
        for(int i = 2;i<nums.size();i++) {
            if(sum>nums[i]) res=sum+nums[i];
            sum+=nums[i];
        }

        if(res==0) return -1;
        return res;
    }
};