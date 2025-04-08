class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();

        for(int& i: nums) mp[i]++;

        int cnt = 0;

        int i = 0;
        int j = 2;

        while(j < n) {
            bool distinct = true;
            for(auto it: mp) {
                if(it.second > 1) {
                    distinct = false;
                    break;
                }
            }
            if(distinct) return cnt;

            for(int k = i;k<=j;k++) mp[nums[k]]--;
            cnt++;

            i+=3;
            j+=3;
        }

        if(!mp.empty()) {
            for(auto it: mp) {
                if(it.second > 1) return cnt+1;
            }
        }

        return cnt;
    }
};