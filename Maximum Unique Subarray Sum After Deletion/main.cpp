class Solution {
public:
    int maxSum(vector<int>& nums) {
        map<int,int> mp;

        for(int& num : nums) mp[num]++;

        bool allNeg = (--mp.end())->first < 0;

        int maxi = 0;

        for(auto& it: mp) {
            if(!allNeg && it.first >= 0) {
                maxi += it.first;
            }
            else {
                if(allNeg) {
                    return (--mp.end())->first;
                }
            }
        }

        return maxi;
    }
};