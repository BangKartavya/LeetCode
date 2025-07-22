class Solution {
    public:
        int maximumUniqueSubarray(vector<int>& nums) {
            int n = nums.size();

            int i = 0;
            int j = 0;

            unordered_map<int, int> mp;

            int sum = 0;
            int temp = 0;

            while(j < n) {
                mp[nums[j]]++;
                temp += nums[j];

                if(j - i + 1 == mp.size()) {
                    sum = max(sum, temp);
                }

                while(mp.size() < j - i + 1) {
                    mp[nums[i]]--;
                    temp -= nums[i];
                    if(mp[nums[i]] == 0) mp.erase(nums[i]);
                    i++;
                }
                j++;
            }

            return sum;
        }
};