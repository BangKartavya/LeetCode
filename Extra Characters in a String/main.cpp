class Solution {
public:
    int dp[51];
    int solve(string& s, unordered_set<string>&st, int i)
    {
        if (i == s.size()) return 0;

        if (dp[i] != -1) return dp[i];
        
        string str = "";
        int mn = s.size();
        for (int j = i; j < s.size(); j++)
        {
            str+=s[j];
            int v=str.size();
           if(st.count(str)){
             v=0;
           }
            mn = min(mn, v+solve(s,st,j+1));
        }
        return dp[i] = mn;
    }
    int minExtraChar(string s, vector<string>& d) 
    {
        memset(dp,-1,sizeof(dp));
        unordered_set<string>st;
        for (string& x : d){
        st.insert(x);
        }
        return solve(s, st, 0);
    }
};