class Solution {
    private:
        int n;
        vector<int> maxLen;
        bool possible(int mid) {
            if(mid == 0) return true;
            int s1 = 0;
            int e1 = mid - 1;
            int s2 = mid;
            int e2 = 2 * mid - 1;

            while(e2 < n) {
                if(maxLen[e1] >= mid && maxLen[e2] >= mid) return true;

                s1++;
                e1++;
                s2++;
                e2++;
            }

            return false;
        }

    public:
        int maxIncreasingSubarrays(vector<int>& nums) {
            n = nums.size();
            vector<int> maxLen(n, 0);
            maxLen[0] = 1;
            for(int i = 1; i < n; i++) {
                if(nums[i] > nums[i - 1]) maxLen[i] = maxLen[i - 1] + 1;
                else maxLen[i] = 1;
            }

            this->maxLen = maxLen;

            int s = 0;
            int e = n / 2;
            int ans = 0;

            while(s <= e) {
                int mid = s + (e - s) / 2;

                if(possible(mid)) {
                    ans = mid;
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }

            return ans;
        }
};