class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int>adj[n];

        for(auto i:prerequisites)
            adj[i[1]].push_back(i[0]);

        vector<vector<int>>mp(n,vector<int>(n));
        for(int i=0;i<n;i++){
            vector<int>vis(n);
            queue<int>q;

            q.push(i);
            vis[i]=1;
            while(q.size()){
                int node=q.front();q.pop();

                for(auto j:adj[node])
                    if(!vis[j])vis[j]=1,mp[j][i]=1,q.push(j);
            }
        }

        vector<bool>ans;
        for(auto i:queries)
            ans.push_back(mp[i[0]][i[1]]);

        return ans;
    }
};