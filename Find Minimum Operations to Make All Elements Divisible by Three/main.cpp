class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            int operations = 0;

            for(int& i : nums) {
                operations += min(i % 3, 3 - (i % 3));
            }

            return operations;
        }
};