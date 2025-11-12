class Solution {
private:
    int gcd(int a, int b) {
        if(b == 0) return a;
        return gcd(b,a%b);
    }
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int startIdx = -1;
        int ones = 0;

        for(int& i: nums) ones += (i == 1);

        if(ones) {
            return n - (ones);
        }

        for(int d=2; d<=n; d++){
            for(int l=0; l<=n-d; l++){
                int g=nums[l]=gcd(nums[l], nums[l+1]);
                if (g==1) return d+n-2;
            }
        }
        return -1;

    }
};