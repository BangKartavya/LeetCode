class Solution {
public:
    int bagOfTokensScore(vector<int> tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int maxi = 0;
        int score = 0;
        int l = 0;
        int r = tokens.size()-1;

        while(l<=r) {
            if(power>=tokens[l]) {
                power-=tokens[l];
                score++;
                l++;
                maxi = max(maxi,score);
            }
            else if (score>0) {
                power+=tokens[r];
                score--;
                r--;
            }
            else break;
        }

        return maxi;
    }
};