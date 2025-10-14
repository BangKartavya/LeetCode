class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int s1 = 0;
        int e1 = k-1;
        int s2 = k;
        int e2 = 2*k -1;
        int n = nums.size();
        int maxLen[n];
        memset(maxLen,0,sizeof(maxLen));
        
        maxLen[0] = 1;
        for(int i = 1;i<n;i++) {
            if(nums[i] > nums[i-1]) maxLen[i] = maxLen[i-1]+1;
            else maxLen[i] = 1;
        }
        
        
        while(e2 < n) {
            if(maxLen[e1] >= k && maxLen[e2] >= k) return true;
        
            s1++;
            e1++;
            s2++;
            e2++;
        }
        
        return false;
    }
};