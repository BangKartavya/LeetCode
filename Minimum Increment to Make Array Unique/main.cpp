class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(begin(nums),end(nums));

        int numTracker = 0;
        int minIncrement = 0;

        for(int i: nums) {
            numTracker = max(numTracker,i);
            minIncrement += numTracker-i;
            numTracker+=1;
        }
        return minIncrement;
    }
};