class UnionFind {
public:
    vector<int> parent;
    vector<int> size;

    UnionFind(int n) {
        for(int i = 0;i<n;i++) parent.push_back(i);
        
        size.resize(n,1);
    }

    int Find(int u) {
        if(u == parent[u]) return u;

        return parent[u] = Find(parent[u]);
    }

    void Union(int u, int v) {
        int a = Find(u);
        int b = Find(v);

        if(a == b) return;

        if(size[a] <= size[b]) {
            size[b] += size[a];
            parent[a] = b;
        }
        else {
            size[a] += size[b];
            parent[b] = a;
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);

        for(vector<int>& edge: edges) {
            uf.Union(edge[0],edge[1]);
        }

        unordered_map<int,unordered_set<int>> components;

        for(int i =0;i<n;i++) {
            int parent = uf.Find(i);
            components[parent].insert(i);
        }

        vector<int> freq(n,0);

        for(vector<int>& edge: edges) {
            freq[uf.Find(edge[0])]++;
        }

        int cnt = 0;

        for(auto it: components) {
            int parent = it.first;

            int siz = it.second.size();


            if(siz*(siz-1)/2 == freq[parent]) cnt++;
        }

        return cnt;
    }
};