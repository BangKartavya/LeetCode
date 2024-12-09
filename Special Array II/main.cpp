class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        vector<int> diff_pre(n,0);

        for(int i = 1;i<n;i++) {
            diff_pre[i] = diff_pre[i-1];
            if(nums[i-1]%2 == nums[i] % 2) {
                diff_pre[i]++;
            }
        }

        vector<bool> ans(q);

        for(int i = 0;i<q;i++) {
            int from = queries[i][0];
            int to = queries[i][1];

            int cnt = diff_pre[to]-(from > 0 ? diff_pre[from] : 0);
            ans[i] = (cnt == 0);

        }

        return ans;
    }
};