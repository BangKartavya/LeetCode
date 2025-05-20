class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        int freq[n+1];
        memset(freq,0,sizeof(freq));

        for(vector<int>& query : queries) {
            freq[query[0]]++;
            freq[query[1]+1]--;
        }

        for(int i = 1;i<=n;i++) {
            freq[i] += freq[i-1]; 
        }

        for(int i = 0;i<n;i++) {
            if(freq[i] < nums[i]) return false; 
        }

        return true;

    }
};