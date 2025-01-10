class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int> mp;

        for(string& word: words2) {
            unordered_map<char,int> wordMp;

            for(char& ch: word) wordMp[ch]++;

            if(mp.empty()) {
                for(auto& it: wordMp) mp[it.first] = it.second;
            }

            for(auto& it: wordMp) {
                mp[it.first] = max(mp[it.first],it.second);
            }
        }

        for(auto& it: mp) {
            cout << "first : " << it.first << endl;
            cout << "second : " << it.second << endl;
        }

        vector<string> result;

        for(string& word: words1) {
            unordered_map<char,int> wordMp;
            bool found = true;

            for(char& ch: word) wordMp[ch]++;

            for(auto& it: mp) {
                if(it.second > wordMp[it.first]) {
                    found = false;
                    break;
                }
            }

            if(found) result.push_back(word);
        }

        return result;
    }
};