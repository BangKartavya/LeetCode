
class Solution {
private:
    int n;
    int dp[2][101][101];
    vector<int> pref;
    int solveForAlice(int i, int player, int M, vector<int>& piles) {
        if(i >= n) return 0;
        if(dp[player][i][M] != -1) return dp[player][i][M];
        int result;
        if(player == 1){// alice wants to maximize
            result = -1;  
        }else{ // bob wants to minimize 
            result = INT_MAX;   
        }
         for (int X = 1; X <= min(2 * M, n - i); X++){
            int currentStones;
            if(i + X <= n){
                if(i > 0){
                    currentStones = pref[i + X - 1] - pref[i - 1];
                }else{
                    currentStones = pref[i + X - 1];
                }
            }else{
                currentStones = 0;
            }
            if(player == 1){
                // Alice's turn, maximize her score
                result = max(result, currentStones + solveForAlice(i + X, 0, max(M, X), piles));
            }else{
                // Bob's turn, minimize Alice's score
                result = min(result, solveForAlice(i + X, 1, max(M, X), piles));
            }
        }

        dp[player][i][M] = result;
        return result;
    }

public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp, -1, sizeof(dp));
        pref.resize(n, 0);
        pref[0] = piles[0]; 
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + piles[i];
        }
        return solveForAlice(0, 1, 1, piles);
    }
};