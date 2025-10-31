class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();

        int x = 0;

        for(int& i: nums) x ^= i;
        for(int i = 0;i<n-2;i++) x ^= i;

        int diffBit = x & (-x);
        int xor1 = 0;
        int xor2 = 0;

        for(int& i: nums) {
            if(i & diffBit) {
                xor1 ^= i;
            }
            else xor2 ^= i;
        }
        for(int i = 0;i<n-2;i++) {
            if(i & diffBit) {
                xor1 ^= i;
            }
            else xor2 ^= i;
        }

        return {xor1,xor2};
    }
};