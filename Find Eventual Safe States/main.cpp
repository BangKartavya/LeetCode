class Solution {
    private:
        vector<vector<int>> adj;
        int n;
        vector<bool> vis;
        vector<bool> curr_path;

        bool dfs(int node) {
            vis[node] = true;
            curr_path[node] = true;

            for(auto i : adj[node]) {
                if(!vis[i]) {
                    if(dfs(i)) {
                        return true;
                    }
                } else if(curr_path[i]) return true;
            }

            return curr_path[node] = false;
        }

    public:
        vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
            this->adj = adj;
            n = adj.size();
            vis.resize(n, false);
            curr_path.resize(n, false);

            for(int i = 0; i < n; i++) {
                if(!vis[i]) {
                    dfs(i);
                }
            }

            vector<int> ans;

            for(int i = 0; i < n; i++) {
                if(!curr_path[i]) ans.push_back(i);
            }

            return ans;
        }
};