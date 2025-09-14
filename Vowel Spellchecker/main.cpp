class Solution {
private:
    string toLower(string s) {
        for(char& ch: s) {
            ch = tolower(ch);
        }

        return s;
    }

    bool isValid(string s, string t) {
        if(s.size() != t.size()) return false;

        string vow = "aeiou";

        for(int i = 0;i<s.size();i++) {
            char ch1 = tolower(s[i]);
            char ch2 = tolower(t[i]);

            if(ch1 == ch2) continue;

            if(ch1 != ch2) {
                if(vow.find(ch1) != string::npos && vow.find(ch2) == string::npos) return false;
                if(vow.find(ch2) != string::npos && vow.find(ch1) == string::npos) return false;
                if(vow.find(ch2) == string::npos && vow.find(ch1) == string::npos) return false;
            }


        }

        return true;
    }

    string normal(string s) {
        string vow = "aeiou";

        for(char& ch: s) {
            if(vow.find(tolower(ch)) != string::npos) ch = 'a';
            else {
                ch = tolower(ch);
            }
        }

        return s;
    }

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string,vector<string>> mp;
        unordered_set<string> s(begin(wordlist),end(wordlist));
        unordered_map<string,vector<string>> normalized;

        for(string& word: wordlist) {
            mp[toLower(word)].push_back(word);
            normalized[normal(word)].push_back(word);
        }

        vector<string> result;

        for(string& query: queries) {
            if(s.find(query) != s.end()) result.push_back(query);
            else if(mp.find(toLower(query)) != mp.end()) result.push_back(mp[toLower(query)][0]);
            else {
                // error case
                string nor = normal(query);

                if(normalized.find(nor) == normalized.end()) result.push_back("");
                else result.push_back(normalized[nor][0]);
            }
        }

        return result;
    }
};