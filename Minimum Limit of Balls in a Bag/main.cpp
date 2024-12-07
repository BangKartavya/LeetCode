class Solution {
private:
    vector<int> nums;
    int n;

    bool isPossible(int mid,int maxOp) {
        for(auto i: nums) {
            maxOp -= (i + mid - 1)/ mid - 1;            
        }

        return maxOp >= 0;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int s = 1;
        int e = 1e9;
        int ans = -1;
        this->nums = nums;
        n = nums.size();

        while(s <= e) {
            int mid = s + (e-s)/2;

            if(isPossible(mid,maxOperations)) {
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
        }

        return ans;



    }
};