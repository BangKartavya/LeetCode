class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& words) {
        unordered_map<string,vector<string>> grp;

        for(string word: words) {
            string key = word;
            sort(key.begin(),key.end());

            if(grp.find(key)==grp.end()) grp[key] = {word};
            else grp[key].push_back(word);
        }
        vector<vector<string>> res;

        for(auto g:grp) {
            res.push_back(g.second);
        }
        return res;
    }
};