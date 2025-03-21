class Solution {
    private:
        vector<vector<string>> ingredients;
        unordered_set<string> s;
        unordered_map<string, int> mp;
        vector<bool> vis;

        void canPrepare(int i) {
            bool canMake = true;

            for(string& ingredient : ingredients[i]) {
                if(s.find(ingredient) == s.end()) {
                    if(mp.find(ingredient) == mp.end()) {
                        canMake = false;
                        break;
                    } else {
                        if(!vis[mp[ingredient]]) {
                            canMake = false;
                            break;
                        }
                    }
                }
            }

            if(canMake) vis[i] = true;
        }

    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            int n = recipes.size();
            vis.resize(n + 1, false);

            this->ingredients = ingredients;

            for(string& supply : supplies)
                s.insert(supply);
            for(int i = 0; i < n; i++)
                mp[recipes[i]] = i;

            vector<string> result;

            for(int i = 0; i < n; i++) {
                for(int i = 0; i < n; i++) {
                    bool oldVis = vis[i];
                    if(!vis[i]) canPrepare(i);
                    if(oldVis != vis[i]) result.push_back(recipes[i]);
                }
            }

            return result;
        }
};