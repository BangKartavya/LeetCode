class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int wordCount = 0;
        int m = pref.size();

        for(string& word: words) {
            if(word.substr(0,m) == pref) wordCount++;
        }

        return wordCount;
    }
};