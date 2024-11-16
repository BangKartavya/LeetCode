
class Solution {
public:
    long long pref[100001];
    int idx[100001];
    
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int res = n + 1;
        int s = 0;
        int e = 0;
        long long sum = 0;
        
        pref[e] = 0, idx[e++] = -1;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            while (s < e && sum - pref[s] >= k)
                res = min(res, i - idx[s++]);
            while (s < e && sum <= pref[e - 1])
                e--;
            pref[e] = sum, idx[e++] = i;
        }
        return res > n ? -1 : res;
    }
};