class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int result = 0;

            for(int& i : nums) {
                int cnt = 0;
                while(i > 0) {
                    cnt++;
                    i /= 10;
                }
                result += (cnt % 2 == 0);
            }

            return result;
        }
};