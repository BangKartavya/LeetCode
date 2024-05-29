class Solution {
public
    int numSteps(string s) {
        int n = s.size();
        int ans = n-1;
        int carry = 0;

        for(int i =n-1;i0;i--) {
            if(s[i]-'0'+carry==1) {
                ans++;
                carry=1;
            }
        }
        return ans+carry;
    }
};