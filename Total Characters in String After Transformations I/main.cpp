class Solution {
private:
    int freq[26];
    const int MOD = 1e9 + 7;
    
    vector<vector<int>> dp;
    
    int helper(char ch,int t) {
        if(t == 0) return 1;
        
        if(dp[ch-'a'][t] != -1) return dp[ch-'a'][t]; 
        
        if(ch == 'z') {
            dp[ch-'a'][t] = (helper('a',t-1) + helper('b',t-1))%MOD;
            return dp[ch-'a'][t];
        }
        
        dp[ch-'a'][t] = (helper(ch+1,t-1))%MOD;
        return dp[ch-'a'][t];
    }
public:
    int lengthAfterTransformations(string s, int t) {
        memset(freq,0,sizeof(freq));
        
        dp.resize(26,vector<int>(t+1,-1));
        
        for(auto i: s) freq[i-'a']++;
        
        
        int ans = 0;
        
        for(char ch = 'a'; ch <= 'z';ch++) {
            if(freq[ch-'a'] == 0) continue;
            
            ans = (ans + ((long long) freq[ch-'a']*(long long) helper(ch,t))%MOD)%MOD;
        }
        
        return ans;
    }
};