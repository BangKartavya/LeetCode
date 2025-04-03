class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);

        for(int i = 1;i<n;i++) {
            prefix[i] = max(prefix[i-1],nums[i-1]);
        }

        for(int i = n-2;i>=0;i--) {
            suffix[i] = max(suffix[i+1],nums[i+1]);
        }


        long long maxi = 0;

        for(int i = 1;i<n;i++) {
            long long test = (long long)(prefix[i]-nums[i])*(long long)suffix[i];
            maxi = max(maxi,test);
        }

        return maxi;

    }
};