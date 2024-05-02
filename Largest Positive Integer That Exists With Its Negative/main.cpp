class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        for(auto i: nums) {
            if(find(nums.begin(),nums.end(),-i)!=nums.end()) return -i;
        }
        
        return -1;

    }
};