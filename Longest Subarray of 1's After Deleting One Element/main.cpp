class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size();

        int ans = 0;

        int freq[2] = {0,0};

        while(j < n) {
            freq[nums[j]]++;

            while(freq[0] > 1) {
                freq[nums[i]]--;
                i++;
            }

            if(freq[0] == 0)
                ans = max(ans,freq[1]-1);
            else ans = max(ans,freq[1]);
            j++;
        }

        return ans;
    }
};