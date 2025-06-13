class Solution {
    private:
        vector<int> nums;
        int p;
        int n;

        bool isValid(int mid) {
            int validPairs = 0;
            for(int i = 0; i < n - 1; i++) {
                if(abs(nums[i] - nums[i + 1]) <= mid) {
                    validPairs++;
                    i++;
                }
            }

            return (validPairs >= p);
        }

    public:
        int minimizeMax(vector<int>& nums, int p) {
            sort(begin(nums), end(nums));

            this->nums = nums;
            this->p = p;
            n = nums.size();

            int s = 0;
            int e = abs(nums[n - 1] - nums[0]);
            int ans = 0;

            while(s <= e) {
                int mid = s + (e - s) / 2;

                if(isValid(mid)) {
                    ans = mid;
                    e = mid - 1;
                } else s = mid + 1;
            }

            return ans;
        }
};