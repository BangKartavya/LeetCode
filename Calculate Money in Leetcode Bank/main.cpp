class Solution {
public:
    int totalMoney(int n) {
        if(n <= 7) return n * (n+1)/2;

        int start = 1;
        int result = 0;

        while(n>=7) {
            result += 7*(2 * start + 6) / 2;
            start++;
            n-=7;
        }

        if(n) {
            result += n * (2 * start + n-1) / 2;
        }

        return result;
    }
};