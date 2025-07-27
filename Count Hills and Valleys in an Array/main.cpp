class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> ans;
        int res = 0;

        for(int& i: nums) {
            if(ans.empty()) ans.push_back(i);
            else if(i != ans.back()) ans.push_back(i);
        }

        for(int i = 1;i<ans.size()-1;i++) {
            if((ans[i] > ans[i-1] && ans[i] > ans[i+1]) ||(ans[i] < ans[i-1] && ans[i] < ans[i+1])) res++;
        }

        return res;
    }
};