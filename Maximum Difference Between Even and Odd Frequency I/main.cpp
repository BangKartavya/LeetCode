class Solution {
public:
    int maxDifference(string s) {
        int freq[26];
        memset(freq,0,sizeof(freq));

        for(char& ch: s) freq[ch-'a']++;

        int result = INT_MIN;
        
        for(int i = 0;i<26;i++) {
            for(int j = 0;j<26;j++) {
                if(freq[i]%2 == 0 && freq[j]%2 != 0 && freq[i] != 0) {
                    result = max(result,freq[j]-freq[i]);
                }
            }
        }

        return result;
        
    }
};