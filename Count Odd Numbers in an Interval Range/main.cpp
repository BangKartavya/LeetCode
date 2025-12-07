class Solution {
public:
    int countOdds(int low, int high) {
        int total = high - low + 1;

        if((total&1) == 0) return total/2;

        if((low & 1) || (high & 1)) return total/2 + 1;

        return total/2;
    }
};