class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int l = 0;

        while(l < n && nums[l] == 1) l++;
        if(l == n) return 0;

        int r = l + 3;

        int operations = 0;

        while(r <= n) {
            // flip
            for(int i = l;i<r;i++) {
                nums[i] = nums[i] == 0 ? 1 : 0;
            }

            operations++;

            while(l < n && nums[l] == 1) l++;
            if(l == n) return operations;
            r = l+3;
        }

        for(int i = 0;i<n;i++) {
            if(nums[i] == 0) return -1;
        }

        return operations;
    }
};