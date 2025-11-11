class Solution {
private:
    vector<string> strs;
    int len;
    int m;
    int n;

    vector<pair<int,int>> count;
    vector<vector<vector<int>>> dp;

    int solve(int i ,int zero, int ones) {
        if(i >= len) return 0;

        if(zero > m || ones > n) return 0;

        if(dp[i][zero][ones] != -1) return dp[i][zero][ones];

        int t0 = count[i].first;
        int t1 = count[i].second;

        int take = 0;
        
        if(zero + t0 <= m && ones + t1 <= n) take = 1 + solve(i+1,zero+t0,ones+t1);

        int noTake = solve(i+1,zero,ones);

        return dp[i][zero][ones] = max(take,noTake);
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        this->strs = strs;
        len = strs.size();
        this->m = m;
        this->n = n;

        dp.resize(len,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        count.resize(len);

        int idx = 0;
        for(string& str: strs) {
            pair<int,int> p;
            for(char& ch: str) {
                p.first += (ch == '0');
                p.second += (ch == '1');
            }
            count[idx++] = (p);
        }


        return solve(0,0,0);
    }
};class Solution {
private:
    vector<string> strs;
    int len;
    int m;
    int n;

    vector<pair<int,int>> count;
    vector<vector<vector<int>>> dp;

    int solve(int i ,int zero, int ones) {
        if(i >= len) return 0;

        if(zero > m || ones > n) return 0;

        if(dp[i][zero][ones] != -1) return dp[i][zero][ones];

        int t0 = count[i].first;
        int t1 = count[i].second;

        int take = 0;
        
        if(zero + t0 <= m && ones + t1 <= n) take = 1 + solve(i+1,zero+t0,ones+t1);

        int noTake = solve(i+1,zero,ones);

        return dp[i][zero][ones] = max(take,noTake);
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        this->strs = strs;
        len = strs.size();
        this->m = m;
        this->n = n;

        dp.resize(len,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        count.resize(len);

        int idx = 0;
        for(string& str: strs) {
            pair<int,int> p;
            for(char& ch: str) {
                p.first += (ch == '0');
                p.second += (ch == '1');
            }
            count[idx++] = (p);
        }


        return solve(0,0,0);
    }
};