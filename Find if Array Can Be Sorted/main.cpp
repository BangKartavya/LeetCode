class Solution {
public:
    int countBits(int n) {
        int cnt = 0;
        
        while(n > 0) {
            cnt += n & 1;
            
            n /= 2;
        }
        
        return cnt;
    }
    bool check(vector<int>& nums) {
        int n = nums.size();
        for(int i =0;i<n-1;i++) {
            if(nums[i] > nums[i+1]) return false;
        }
        return true;
    }
    bool canSortArray(vector<int>& nums) {
        if(check(nums)) return true;
        int n = nums.size();
        vector<int> cntarr(n);
        
        for(int i = 0;i<n;i++) cntarr[i] = countBits(nums[i]);
        
        for(int j = 0;j<n;j++) {    
            for(int i = 0;i<n-1;i++) {
                if(cntarr[i] == cntarr[i+1] && nums[i] > nums[i+1]) {
                    swap(nums[i],nums[i+1]);
                }
            }
            if(check(nums)) return true;
        }
        
        return false;
    }
};