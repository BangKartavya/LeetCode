class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> res;
        int num = 0;

        for(int& i: nums) {
            num*=2;
            num += i;

            res.push_back(num%5 == 0);
            num %= 5;
        }

        return res;
    }
};