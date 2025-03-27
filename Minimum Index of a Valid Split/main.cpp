class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int dominant = -1;
        int cnt = 0;
        int n = nums.size();

        for(int i = 0;i<n;i++) {
            if(nums[i] == dominant) {
                cnt++;
            }
            else {
                cnt--;
                if(cnt <= 0) {
                    dominant = nums[i];
                    cnt = 1;
                }
            }
        }
        
        vector<int> prefix(n);
        prefix[0] = nums[0] == dominant;
        for(int i = 1;i<n;i++) {
            prefix[i] = prefix[i-1] + (nums[i] == dominant ? 1 : 0);
        }

        for(int j = 0;j<n;j++) {
            if(j == 0 && prefix[0] == 1) {
                if(prefix[n-1]-prefix[0] > (n-1)/2) return 0;
            }
            else if(prefix[j]-prefix[0] > (j+1)/2 && prefix[n-1]-prefix[j] > (n-1-j)/2) return j;
        }

        return -1;

    }
};