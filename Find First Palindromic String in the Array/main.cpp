class Solution {
public:
    bool isPal(string s) {
        for(int i =0;i<s.size();i++) {
            if(s[i] != s[s.size()-i-1]) return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto i:words) {
            if(isPal(i)) return i;
        }
        return "";
    }
};