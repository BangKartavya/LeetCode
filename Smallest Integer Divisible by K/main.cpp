class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if((k % 2 == 0) || (k % 5 == 0)) return -1;

        long long int num = 1;
        int len = 1;
        while(num % k != 0) {
            num *= 10;
            num++;
            num %= k;
            len++;
        }

        return len;
    }
};