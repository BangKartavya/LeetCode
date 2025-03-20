class UnionFind {
    private:
        vector<int> size;
        vector<int> parent;
    public:
    
    UnionFind(int n) {
        size.resize(n,1);
        
        for(int i = 0;i<n;i++) {
            parent.push_back(i);
        }
    }

    int Find(int u) {
        if(u == parent[u]) return u;

        return parent[u] = Find(parent[u]);
    }

    void Union(int u ,int v) {
        int ultimateU = Find(u);
        int ultimateV = Find(v);
    
        if(ultimateU == ultimateV) return;

        if(size[ultimateU] > size[ultimateV]) {
            size[ultimateU] += size[ultimateV];
            parent[ultimateV] = ultimateU;
        }
        else {
            size[ultimateV] += size[ultimateU];
            parent[ultimateU] = ultimateV;    
        }

    }
    bool connected(int x, int y) {
        return Find(x) == Find(y);
    }

};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) 
    {
        UnionFind graph(n);
        vector<unsigned> cost(n, UINT_MAX);
        for (auto& vec: edges){
            int u=vec[0], v=vec[1], w=vec[2];
            int wt=cost[graph.Find(u)] & cost[graph.Find(v)] & w;
            graph.Union(u, v);
            int rt=graph.Find(u);
            cost[rt]&=wt;
        }
        int m=query.size();
        vector<int> ans(m, -1);
        for(int i=0; i<m; i++){
            int s=query[i][0], t=query[i][1];
            if (graph.connected(s, t))
                ans[i]=cost[graph.Find(s)];
        }
        return ans;
    }
};
