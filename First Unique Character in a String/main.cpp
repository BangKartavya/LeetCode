class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26,0);
        vector<int> pos_ans;

        for(int i =0;i<s.size();i++) {
            freq[s[i]-'a']++;
            if(freq[s[i]-'a']==1) pos_ans.push_back(i);
        }

        for(auto i : pos_ans) {
            if(freq[s[i]-'a']==1) return i;
        }
        return -1;
    }
};