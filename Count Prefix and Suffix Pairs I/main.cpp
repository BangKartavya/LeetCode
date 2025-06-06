class Solution {
public:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        int n = str1.size(), m = str2.size();
        if (n > m) return false; // str1 cannot be prefix and suffix if it is longer than str2
        return str2.substr(0, n) == str1 && str2.substr(m - n, n) == str1;
    }
    
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        int n = words.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        
        return count;
    }
};