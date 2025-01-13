class Solution {
    public:
        int minimumLength(string s) {
            vector<int> fre(26, 0);
            for(char x : s)
                fre[x - 'a']++;
            int res = 0;
            for(int i = 0; i < 26; i++) {
                if(fre[i] == 0) continue;
                if(fre[i] % 2 == 1) res++;
                else res += 2;
            }
            return res;
        }
};