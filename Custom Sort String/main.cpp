class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> charCount;

        for(char c: order) charCount[c]=0;

        for(char c: s) {
            if(charCount.find(c)!=charCount.end()) charCount[c]++;
        }

        string ans;

        for(char c: order) ans.append(charCount[c],c);
        for(char c: s) if(charCount.find(c)==charCount.end()) ans.push_back(c);

        return ans;

    }
};