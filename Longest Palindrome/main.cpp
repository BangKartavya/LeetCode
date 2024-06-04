class Solution {
public:
    int longestPalindrome(string s) {
        int oddFreq = 0;
        unordered_map<char,int> mp;

        for(auto i: s) {
            mp[i]++;
            if(mp[i]%2) oddFreq++;
            else oddFreq--;
        }
        if(oddFreq>1) return s.length()-oddFreq+1;
        return s.length();
    }
};