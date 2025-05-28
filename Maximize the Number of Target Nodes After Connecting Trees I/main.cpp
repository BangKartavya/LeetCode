class Solution {
private:
    int dfs(vector<vector<int>>& adj, int node, int parent,int k) {
        if(k < 0) return 0;
        int count = 1;

        for(int& it: adj[node]) {
            if(it != parent) count += dfs(adj,it,node,k-1);
        }

        return count;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size();
        int m = edges2.size();

        vector<vector<int>> adj1(n+1);
        vector<vector<int>> adj2(m+1);

        for(vector<int>& edge: edges1) {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        for(vector<int>& edge: edges2) {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        int maxB = 0;
        vector<int> answer(n+1);

        for(int i = 0;i<=m;i++) {
            maxB = max(maxB,dfs(adj2,i,-1,k-1));
        }
        for(int i = 0;i<=n;i++) {
            answer[i] = max(answer[i],dfs(adj1,i,-1,k) + maxB);
        }
        


        return answer;

    }
};