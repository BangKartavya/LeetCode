class Solution {
    public:
        long long zeroFilledSubarray(vector<int>& nums) {
            long long result = 0;

            int nonZeros = 0;
            int n = nums.size();

            int i = 0;
            int j = 0;

            while(j < n) {
                nonZeros += (nums[j] != 0);

                while(nonZeros > 0 && i < j) {
                    nonZeros -= (nums[i] != 0);
                    i++;
                }

                if(nonZeros == 0) {
                    result += (long long)(j - i + 1);
                }

                j++;
            }

            return result;
        }
};