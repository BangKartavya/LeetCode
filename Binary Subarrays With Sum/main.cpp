class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> cnt;
        cnt[0] = 1;
        int curSum = 0;
        int totalSub = 0;

        for(int num : nums) {
            curSum+=num;
            if(cnt.find(curSum-goal)!=cnt.end()) totalSub+= cnt[curSum-goal];
            cnt[curSum]++;
        }
        return totalSub;
    }
};