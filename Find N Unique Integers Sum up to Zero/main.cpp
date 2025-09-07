class Solution {
public:
    vector<int> sumZero(int n) {
        if(n == 1) return {0};
        vector<int> result(n);

        int i = 0;

        while(i < (n+1)/2) {
            result[i] = -(n/2-i);
            result[n-i-1] = n/2-i;
            i++;
        }

        return result;
    }
};