class Solution {
public:
    void sortColors(vector<int>& nums) {
        int v[3] = {0,0,0};
        for(auto i: nums) v[i]++;
        int k = 0;
        for(int i =0;i<3;i++) {
            for(int j = 0;j<v[i];j++) {
                nums[k++] = i;
            }
        }
    }
};