class Solution {
    public:
        int minLength(string s) {
            stack<char> stk;

            for(auto i : s) {
                if(!stk.empty()) {
                    if(stk.top() == 'A' && i == 'B') stk.pop();
                    else if(stk.top() == 'C' && i == 'D') stk.pop();
                    else stk.push(i);
                } else stk.push(i);
            }

            return stk.size();
        }
};