class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;

        for(auto i: details) {
            int fDigit = i[11]-'0';
            int sDigit = i[12]-'0';

            if(fDigit > 6 || (fDigit == 6 && sDigit > 0)) ans++;
        }
        return ans;
    }
};