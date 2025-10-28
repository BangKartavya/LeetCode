class Solution {
private:
    int n;
    bool isValid(int curr, int right, vector<int> nums,int sum) {
        while(curr >= 0 && curr < n) {
            if(nums[curr] == 0) curr += right;
            else if(nums[curr] < 0) return false;
            else {
                nums[curr]--;
                sum--;
                right = right == 1 ? -1 : 1;
                curr += right;
            }
        }
        return sum == 0;
    }
public:
    int countValidSelections(vector<int>& nums) {
        n = nums.size();
        int res = 0;
        int sum = accumulate(begin(nums),end(nums),0);

        for(int i = 0;i<n;i++) {
            if(nums[i] == 0) {
                res += isValid(i,1,nums,sum);
            }
        }
        
        for(int i = 0;i<n;i++) {
            if(nums[i] == 0) {
                res += isValid(i,-1,nums,sum);
            }
        }

        return res;
    }
};