class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26] = {0};

        for(char& ch: s) {
            freq[ch-'a']++;
        }

        int ans = 0;

        ans += max({freq[0],freq[4],freq[8],freq[14],freq[20]});
        freq[0] = 0;
        freq[4] = 0;
        freq[8] = 0;
        freq[14] = 0;
        freq[20] = 0;
        ans += *max_element(freq, freq+26);

        return ans;
    }
};