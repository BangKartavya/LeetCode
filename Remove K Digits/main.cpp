class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk;

        for(char d : num) {
            while(k>0 && !stk.empty() && d<stk.top()) {
                stk.pop();
                k--;
            }
            stk.push(d);
        }
        while(k>0 && !stk.empty()) {
            stk.pop();
            k--;
        }

        string temp= "";
        while(!stk.empty()) {
            temp+=stk.top();
            stk.pop();
        }

        reverse(temp.begin(),temp.end());

        int m = temp.size();
        string res = "";
        int fNoZ = 0;

        for(int i =0;i<m;i++) {
            if(temp[i]=='0' && fNoZ == 0) continue;
            else {
                res+=temp[i];
                fNoZ = 1;
            }
        }
        if(res.size()==0) res+='0';

        return res;
    }
};