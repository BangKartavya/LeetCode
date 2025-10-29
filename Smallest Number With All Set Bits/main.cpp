class Solution {
public:
    int smallestNumber(int n) {
        int i = 0;

        for(int i = 0;i<32;i++) if((1<<i)-1 >= n) return (1 << i) - 1;

        return pow(2,32)-1;
    }
};