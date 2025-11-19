class Solution {
    private:
        int binarySearch(vector<int>& nums, int val) {
            int s = 0;
            int e = nums.size() - 1;

            while(s <= e) {
                int mid = s + (e - s) / 2;

                if(nums[mid] == val) return mid;
                else if(nums[mid] < val) {
                    s = mid + 1;
                } else e = mid - 1;
            }

            return -1;
        }

    public:
        int findFinalValue(vector<int>& nums, int original) {
            sort(begin(nums), end(nums));

            while(binarySearch(nums, original) != -1) {
                original <<= 1;
            }

            return original;
        }
};