class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i =2;i*i<=c;i++) {
            if(!(c%i)) {
                int exp = 0;

                while(!(c%i)) {
                    exp++;
                    c/=i;
                }
                if(i%4 == 3 && exp%2 != 0) return false;
            }
        }
        return c%4!=3;
    }
};