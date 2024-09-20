class Solution {
public:
    string shortestPalindrome(string s) {
        const int n = s.size();

        int i = 0;
        for(int j = n-1;j>=0;j--) {
            if(s[i] == s[j]) i++;
        }
        if(i == n) return s;

        string sub = s.substr(i);
        string rem = sub;

        reverse(begin(rem),end(rem));

        return rem + shortestPalindrome(s.substr(0,i)) + sub;
    }
};