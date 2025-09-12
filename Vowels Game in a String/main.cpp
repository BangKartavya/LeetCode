class Solution {
public:
    bool doesAliceWin(string s) {
        string v = "aeiou";

        for(char& ch: s) if(v.find(ch) != string::npos) return true;

        return false;

    }
};