class Solution {
    public:
        long long minimumSteps(string s) {
            unsigned long long int white = 0;
            unsigned long long int res = 0;
            int n = s.length();

            for(auto i : s) {
                if(i == '0') res += white;
                else if(i == '1') white++;
            }

            return res;
        }
};