class Solution {
public:
    bool canChange(string s, string t) {
        int n = s.size();

        for(int i = 0,j = 0;i<n || j < n;i++,j++) {
            while(i < n && s[i] == '_') i++;
            while(j < n && t[j] == '_') j++;

            char c = s[i];

            if(c != t[j]) {
                return false;
            }
            if((c == 'L' && i < j) || (c == 'R' && i>j)) {
                return false;
            }
        }
        return true;
    }
};