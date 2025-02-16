class Solution {
    private:
        int n;
        int total;

        unsigned long long int vis = 0;
        vector<int> ans;

        int dfs(int i) {
            if(i == total) {
                return popcount(vis) == n;
            }
            if(ans[i] != 0) return dfs(i + 1);

            for(int j = n; j >= 1; j--) {
                if((vis >> j) & 1) continue;
                else {
                    int nextPos = (j > 1) ? i + j : i;

                    if(nextPos >= total || ans[nextPos] != 0) continue;

                    ans[i] = ans[nextPos] = j;
                    vis |= (1 << j);

                    if(dfs(i + 1)) return 1;

                    ans[i] = ans[nextPos] = 0;
                    vis &= ~(1 << j);
                }
            }
            return 0;
        }

    public:
        vector<int> constructDistancedSequence(int n) {
            this->n = n;
            total = 2 * n - 1;
            ans.resize(total, 0);
            dfs(0);
            return ans;
        }
};