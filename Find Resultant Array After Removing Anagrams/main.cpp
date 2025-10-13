class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        unordered_map<string,vector<string>> mp;

        for(string& w: words) {
            string temp = w;
            sort(begin(w),end(w));
            mp[w].push_back(temp);
        }   

        vector<string> result;
        result.push_back(mp[words[0]][0]);

        for(int i = 1;i<words.size();i++) {
            if(words[i-1] == words[i]) {
                continue;
            }
            else {
                result.push_back(mp[words[i]][0]);
            }
        }

        return result;
    }
};