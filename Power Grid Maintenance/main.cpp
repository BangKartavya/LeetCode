class UnionFind {
public:
    vector<int> parent;
    vector<long long> size;
    unordered_map<int,set<int>> mp;
    int n;

    UnionFind(int n) {
        this->n = n;
        parent.resize(n+1);
        size.resize(n+1,1);

        for(int i = 1;i<=n;i++) parent[i] = i;
    }

    int Find(int u) {
        if(parent[u] == u) return u;
        return parent[u] = Find(parent[u]);
    }

    void Union(int u, int v) {
        int parU = Find(u);
        int parV = Find(v);

        if(parU == parV) return;

        if(size[parU] < size[parV]) {
            parent[parU] = parV;
            size[parV] += size[parU];
        }
        else {
            parent[parV] = parU;
            size[parU] += size[parV];
        }
    }

    void map() {
        for(int i = 1;i<=n;i++) {
            mp[Find(i)].insert(i);
        }
    }
};

class Solution {
private:
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result;

        UnionFind* uf = new UnionFind(c);

        for(vector<int>& conn: connections) {
            uf->Union(conn[0],conn[1]);
        }

        uf->map();

        for(vector<int>& query: queries) {
            int x = query[0];
            int station = query[1];
            int par = uf->parent[station];

            if(x == 2) {
                uf->mp[par].erase(station);
            }
            else {
                if(uf->mp[par].find(station) != uf->mp[par].end()) {
                    result.push_back(station);
                }
                else {
                    if(!uf->mp[par].empty()) {
                        result.push_back(*(uf->mp[par].begin()));
                    }
                    else result.push_back(-1);
                }
            }
        }
        delete uf;
        return result;
    }
};