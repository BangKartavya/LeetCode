class Solution {
    public:
        string smallestNumber(string pattern) {
            int n = pattern.size();
            string ans;
            stack<char> stk;
            stk.push('1');

            for(char& ch : pattern) {
                char maxi = stk.top();
                if(ch == 'I') {
                    while(!stk.empty()) {
                        maxi = max(maxi, stk.top());
                        ans += stk.top();
                        stk.pop();
                    }
                }
                stk.push(maxi + 1);
            }

            while(!stk.empty()) {
                ans += stk.top();
                stk.pop();
            }

            return ans;
        }
};