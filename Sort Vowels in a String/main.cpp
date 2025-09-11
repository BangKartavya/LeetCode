class Solution {
public:
    string sortVowels(string s) {
        int low[26] = {0};
        int high[26] = {0};
        string st = "aeiouAEIOU";

        for(char& ch: s) {
            if(st.find(ch) != string::npos) {
                if(ch-'a' < 0) {
                    high[ch-'A']++;
                }
                else low[ch-'a']++;

                ch = '#';
            }
        }

        string v;

        for(char i = 'A'; i <= 'Z';i++) {
            while(high[i-'A']) {
                v.push_back(i);
                high[i-'A']--;
            }
        }
        for(char i = 'a'; i <= 'z';i++) {
            while(low[i-'a']) {
                v.push_back(i);
                low[i-'a']--;
            }
        }

        int i = 0;
        for(char& ch: s) {
            if(ch == '#') {
                ch = v[i++];
            }
        }

        return s;
    }
};