class Solution {
public:
    void helper(vector<int>& jd,int d,int idx,vector<vector<int>>& memo) {
        int len = jd.size();
        if(memo[d][idx]!=0) return;
        if(d==1) {
            int num = 0;
            for(int i =idx;i<len;i++) num = max(num,jd[i]);
            memo[d][idx]=num;
            return;
        }
        int maxDifficulty = jd[idx];
        d--;
        
        int stop = len-idx-d+1;
        int result = INT_MAX;
        
        for(int i =1;i<stop;i++) {
            maxDifficulty = max(maxDifficulty,jd[idx+i-1]);
            int other = memo[d][idx+i];
            
            if(other==0) {
                helper(jd,d,idx+i,memo);
                other = memo[d][idx+i];
            }
            result = min(result,other+maxDifficulty);
            
        }
        memo[d+1][idx]=result;
        
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size()<d) return -1;
        if(jobDifficulty.size()==d) return accumulate(jobDifficulty.begin(),jobDifficulty.end(),0);
        
        int sum = accumulate(jobDifficulty.begin(),jobDifficulty.end(),0);
        if(sum==0) return 0;
        vector<vector<int>> memo(d + 1, vector<int>(jobDifficulty.size(), 0));
        helper(jobDifficulty, d, 0, memo);
        
        return memo[d][0];
    }
};