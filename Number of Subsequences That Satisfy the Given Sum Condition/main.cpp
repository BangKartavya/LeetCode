class Solution {
private:
    const int MOD = 1e9 + 7;
    
    int binExpo(int a, int b) {
        int res = 1;

        while(b > 0) {
            if(b%2 == 1) {
                res = ((long long int)(res%MOD)*(long long int)(a%MOD))%MOD;
                b--;
            }
            else {
                a = ((long long int)(a%MOD)*(long long int)(a%MOD))%MOD;
                b/=2;
            }
        }

        return res;
    }
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
        int n = nums.size();

        int result = 0;

        for(int i = 0;i<n;i++) {
            if(2*nums[i] > target) break;
            int justGreater = upper_bound(begin(nums),end(nums),target-nums[i]) - begin(nums);
            result = (result + binExpo(2,justGreater-i-1))%MOD;
        }

        return result;

    }
};