class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> c(26,0);
        
        for(int i =0;i<s.size();i++) {
            c[s[i]-'a']--;
            c[t[i]-'a']++;
        }
        
        int ans = 0;
        
        for(auto i: c) if(i>=0) ans+=i;
        
        return ans;
    }
};