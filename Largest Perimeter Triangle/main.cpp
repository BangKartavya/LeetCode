class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n = nums.size();

        for(int i = n-1;i>=2;i--) {
            int j = i-1;
            int k = i-2;

            int a = nums[i];
            int b = nums[j];
            int c = nums[k];

            if(b + c > a) {
                return a + b + c;
            }
        }

        return 0;
    }
};