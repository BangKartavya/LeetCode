class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int x = 0;
        int y = 0;

        for(int& i: nums1) x ^= i;
        for(int& i: nums2) y ^= i;

        return (nums1.size() % 2 * y) ^ (nums2.size() % 2 * x);

    }
};