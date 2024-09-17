class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string ,int> mp;

        string temp;
        for(auto i: s1) {
            if(i == ' ') {
                mp[temp]++;
                temp = "";
            }
            else temp += i;
        }
        mp[temp]++;
        temp = "";
        for(auto i: s2) {
            if(i == ' ') {
                mp[temp]++;
                temp = "";
            }
            else temp += i;
        }
        mp[temp]++;
        vector<string> ans;

        for(auto i: mp) if(i.second == 1) ans.push_back(i.first);

        return ans;


    }
};