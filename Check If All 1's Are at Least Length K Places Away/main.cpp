class Solution {
    public:
        bool kLengthApart(vector<int>& nums, int k) {
            int lastOnePos = -1;
            int n = nums.size();

            for(int i = 0; i < n; i++) {
                if(nums[i] == 1) {
                    if(lastOnePos == -1) {
                        lastOnePos = i;
                    } else {
                        if((i - lastOnePos - 1) < k) return false;
                        else lastOnePos = i;
                    }
                }
            }

            return true;
        }
};