class Solution {
    public:
        int maxOperations(string s) {
            int res = 0;
            int ones = 0;
            bool cut = 0;

            for(char& ch : s) {
                if(ch == '0') {
                    cut = true;
                } else {
                    if(cut) res += ones;
                    ones++;
                    cut = false;
                }
            }

            if(cut) res += ones;

            return res;
        }
};