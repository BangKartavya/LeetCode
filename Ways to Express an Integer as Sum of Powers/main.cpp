class Solution {
private:
    int x;
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    vector<int> arr;

    int binExpo(int a,int b) {
        int res = 1;

        while(b) {
            if(b%2) {
                res = (res%MOD * a%MOD)%MOD;
                b--;
            }
            else {
                a = (a%MOD * a%MOD)%MOD;
                b/=2;
            }
        }

        return res;
    }
    long long int solve(int i, int sum) {
        if(sum == 0) return 1;
        if(i < 0) return 0;

        if(dp[i][sum] != -1) return dp[i][sum];

        int curr = arr[i];

        int ans = 0;

        if(curr <= sum) {
            ans = solve(i-1,sum-curr)%MOD;
        }
        
        ans = (ans + solve(i-1,sum))%MOD;

        return dp[i][sum] = ans;

    }
public:
    int numberOfWays(int n, int x) {
        this->x = x;

        for(int i = 1;;i++) {
            int p = binExpo(i,x);

            if(p > n) break;

            arr.push_back(p);
        }

        dp.resize(arr.size(),vector<int>(n+1,-1));
        return solve(arr.size()-1,n);
    }
};