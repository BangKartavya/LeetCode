class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int n = nums.size();

       int partitions = 1;
       int s = 0;
       int e = 0;

       while(e < n) {
            if(nums[e] - nums[s] <= k) {
                e++;
            }
            else {
                partitions++;
                s = e;
            }
        }
        return partitions;
    }
};