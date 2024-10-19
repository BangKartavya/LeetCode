class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;

        for(auto i: expression) {
            if(i == ',' || i == '(') continue;

            if(i == 't' || i == 'f' || i == '!' || i == '&' || i == '|') stk.push(i);

            else if(i == ')') {
                bool hasTrue = false;
                bool hasFalse = false;

                while(stk.top() != '!' && stk.top() != '&' && stk.top()!='|') {
                    char top = stk.top();
                    stk.pop();
                    if(top == 't') hasTrue = true;
                    if(top == 'f') hasFalse = true;
                }

                char op = stk.top();
                stk.pop();
                if(op == '!') {
                    stk.push(hasTrue ? 'f' : 't');
                }
                else if(op == '&') {
                    stk.push(hasFalse ? 'f' : 't');
                }
                else stk.push(hasTrue ? 't' : 'f');
            }
        }

        return stk.top() == 't';
    }
};