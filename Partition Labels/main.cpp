class Solution {
private:
    int freq[26];
    int mp[26];

    bool isValid() {
        for(int i =0;i<26;i++) {
            if(mp[i] != 0) {
                if(mp[i] != freq[i]) return false;
            }
        }

        return true;
    }

public:
    vector<int> partitionLabels(string s) {
        memset(freq,0,sizeof(freq));
        memset(mp,0,sizeof(mp));

        for(char& ch: s) freq[ch-'a']++;

        vector<int> result;
        int n = s.size();
        int last = 0;
        
        for(int i = 0;i<n;i++) {
            mp[s[i]-'a']++;

            if(isValid()) {
                result.push_back(i-last+1);
                memset(mp,0,sizeof(mp));
                last = i+1;
            }
        }

        return result;
    }
};