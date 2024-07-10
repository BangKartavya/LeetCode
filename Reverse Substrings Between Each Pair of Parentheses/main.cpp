class Solution {
public:
    string reverseParentheses(string s) {
        vector<string> stk;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                stk.push_back("(");
            } else if(s[i] == ')') {
                string rev = "";
                while(stk.size() > 0 && stk.back() != "(") {
                    reverse(stk.back().begin(), stk.back().end());
                    rev += stk.back();
                    stk.pop_back();
                }
                stk.pop_back();
                stk.push_back(rev);
            } else {
                stk.push_back(string(1, s[i]));
            }
        }
        
        string ans = std::accumulate(stk.begin(), stk.end(), std::string());
        return ans;
    }
};