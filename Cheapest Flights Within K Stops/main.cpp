class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;

        for(auto f: flights) adj[f[0]].push_back({f[1],f[2]});

        vector<int> dist(n,INT_MAX);
        dist[src] = 0;

        queue<pair<int,int>> q;
        q.push({src,0});
        int stops = 0;

        while(!q.empty() && stops <=k) {
            int sz = q.size();
            while(sz-->0) {
                auto [node,distance] = q.front();
                q.pop();
                if(!adj.count(node)) continue;

                for(auto [nei,price]: adj[node]) {
                    if(price+distance>=dist[nei]) continue;
                    dist[nei] = price+distance;
                    q.push({nei,dist[nei]});
                }
            }
            stops++;
        } 
        return dist[dst]==INT_MAX ? -1 : dist[dst];
    }
};