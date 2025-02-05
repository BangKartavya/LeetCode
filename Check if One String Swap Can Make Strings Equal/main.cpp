class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;
        int n = s1.size();
        int charsOutOfPlace = 0;

        int freq[26];
        memset(freq,0,sizeof(freq));

        for(char& ch: s1) freq[ch-'a']++;
        for(char& ch: s2) freq[ch-'a']--;

        for(int i = 0;i<26;i++) if(freq[i] != 0) return false;        

        for(int i = 0;i<n;i++) {
            if(s1[i] != s2[i]) charsOutOfPlace++;
        }

        if(charsOutOfPlace == 2) return true;

        return false;
    }
};