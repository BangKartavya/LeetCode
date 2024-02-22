class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n+1);
        vector<int> out(n+1);

        for(auto i : trust) {
            in[i[0]]++;
            out[i[1]]++;
        }

        for(int i = 1;i<=n;i++) {
            if(out[i]==n-1 && in[i] == 0) return i;
        }
        return -1;
    }
};