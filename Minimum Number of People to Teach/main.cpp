class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        set<int> need;

        for(vector<int>& friends: friendships) {
            int u = friends[0] - 1;
            int v = friends[1] - 1;

            bool can = false;

            for(int& x: languages[u]) {
                for(int& y: languages[v]) {
                    if(x == y) {
                        can = true;
                        break;
                    }
                }
            }

            if(!can) {
                need.insert(u);
                need.insert(v);
            }
        }

        int ans = languages.size() + 1;

        for(int i = 1;i<=n;i++) {
            int canSpeak = 0;
            for(const int& v: need) {
                bool found = false;
                for(int& c: languages[v]) {
                    if(c == i) {
                        found = true;
                        break;
                    }
                }
                if(!found) canSpeak++;
            }
            ans = min(ans,canSpeak);
        }

        return ans;
    }
};