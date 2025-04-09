class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));

        if(k > nums[0]) return -1;
        int n = nums.size();
        int cnt = 0;
        unordered_set<int> s;
        
        for(int i = 0;i<n;i++) {
            if(nums[i] != k) s.insert(nums[i]);
        }

        return s.size();
    }
};