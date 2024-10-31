class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        ans += s[0];
        int n = s.size();
        int cnt = 1;

        for(int i = 1;i<n;i++) {
            if(s[i] == ans.back()) {
                cnt++;
                if(cnt < 3) ans+=s[i];
            }
            else {
                cnt = 1;
                ans += s[i];
            }
        }
        return ans;
    }
};