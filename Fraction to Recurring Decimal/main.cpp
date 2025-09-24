class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";

        string frac;

        if((numerator < 0) ^ (denominator < 0)) frac += "-";

        long long divi = (long long)numerator;
        long long div = (long long)denominator;

        long long num = divi/div;
        frac += to_string(abs(num));
        long long rem = divi%div;

        if(rem == 0) {
            return frac;
        } 

        frac += ".";
        unordered_map<int,int> mp;

        while(rem) {
            if(mp.count(rem)) {
                frac.insert(mp[rem],"(");
                frac += ")";
                break;
            }

            mp[rem] = frac.size();
            rem*=10;
            frac += to_string(abs(rem)/abs(div));
            rem %= div;
        }

        return frac;
    }
};