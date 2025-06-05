class DisjointSet {
    private:
        std::vector<int> rank;
        std::vector<int> parent;
        std::vector<int> size;
        std::vector<int> path;

    public:
        DisjointSet(int n) {
            rank.resize(n + 1, 0);
            size.resize(n + 1);
            parent.resize(n + 1);

            for(int i = 0; i <= n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUltimateParent(int node) {
            path.push_back(node);
            if(node == parent[node]) {
                sort(begin(path), end(path));
                int ans = path[0];
                path.clear();
                return ans;
            }

            return parent[node] = findUltimateParent(parent[node]);
        }

        void unionByRank(int u, int v) {
            int ultimateParentOfu = findUltimateParent(u);
            int ultimateParentOfv = findUltimateParent(v);

            if(ultimateParentOfu == ultimateParentOfv) return;

            int rankOfu = rank[ultimateParentOfu];
            int rankOfv = rank[ultimateParentOfv];

            if(rankOfu < rankOfv) {
                parent[ultimateParentOfu] = ultimateParentOfv;
            } else if(rankOfv < rankOfu) {
                parent[ultimateParentOfv] = ultimateParentOfu;
            } else {
                parent[ultimateParentOfv] = ultimateParentOfu;
                rank[ultimateParentOfu]++;
            }
        }

        void unionBySize(int u, int v) {
            int ultimateParentOfu = findUltimateParent(u);
            int ultimateParentOfv = findUltimateParent(v);

            if(ultimateParentOfu == ultimateParentOfv) return;

            int sizeOfu = size[ultimateParentOfu];
            int sizeOfv = size[ultimateParentOfv];

            if(ultimateParentOfu < ultimateParentOfv) {
                parent[ultimateParentOfv] = ultimateParentOfu;
                size[ultimateParentOfu] += size[ultimateParentOfv];

                return;
            } else {
                parent[ultimateParentOfu] = ultimateParentOfv;
                size[ultimateParentOfv] += size[ultimateParentOfu];
                return;
            }
        }
};

class Solution {
    public:
        string smallestEquivalentString(string s1, string s2, string baseStr) {
            DisjointSet ds(26);

            int n = s1.size();
            int m = baseStr.size();

            for(int i = 0; i < n; i++) {
                ds.unionBySize(s1[i] - 'a', s2[i] - 'a');
            }

            string equivalent;

            for(int i = 0; i < m; i++) {
                equivalent += (ds.findUltimateParent((baseStr[i] - 'a')) + 'a');
            }

            return equivalent;
        }
};