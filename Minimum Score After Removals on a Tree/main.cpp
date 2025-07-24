class Solution {
public:
    unordered_set<int> v[1002];
    bool vis[1002];

    int ans = INT_MAX, comp_1, comp_2, comp_3;

    int dfs(int i, vector<int>& a) {
        int curr = a[i];

        vis[i] = true;

        for (auto x : v[i]) {
            if (!vis[x]) {
                curr = curr ^ dfs(x, a);
            }
        }

        return curr;
    }

    int dfs1(int i, int j, vector<int>& a) {
        vis[i] = true;

        int curr = a[i];

        for (auto x : v[i]) {
            if (!vis[x]) {
                int res = dfs1(x, j, a);

                comp_2 = res;
                comp_3 = j ^ res;

                ans = min(ans, max(comp_1, max(comp_2, comp_3)) -
                                   min(comp_1, min(comp_2, comp_3)));

                curr = curr ^ res;
            }
        }

        return curr;
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {

        for (auto x : edges) {
            v[x[0]].insert(x[1]);
            v[x[1]].insert(x[0]);
        }

        int val = 0;

        for (auto x : nums) {
            val = val ^ x;
        }

        ans = INT_MAX;

        for (auto x : edges) {
            v[x[0]].erase(x[1]);
            v[x[1]].erase(x[0]);

            for (int i = 0; i <= nums.size(); i++) {
                vis[i] = false;
            }

            comp_1 = dfs(0, nums);

            int pos;

            for (int i = 0; i < nums.size(); i++) {
                if (!vis[i]) {
                    pos = i;
                    dfs1(i, comp_1 ^ val, nums);
                }
            }

            for (int i = 0; i <= nums.size(); i++) {
                vis[i] = false;
            }

            comp_1 = dfs(pos, nums);

            for (int i = 0; i < nums.size(); i++) {
                if (!vis[i]) {
                    dfs1(i, comp_1 ^ val, nums);
                }
            }
            v[x[0]].insert(x[1]);
            v[x[1]].insert(x[0]);
        }
        return ans;
    }
};