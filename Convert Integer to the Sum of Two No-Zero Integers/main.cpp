class Solution {
private:
    bool isValid(int n) {
        if(n == 0) return false;

        while(n > 0) {
            if(n%10 == 0) return false;
            n/=10;
        }

        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1;i<n;i++) {
            int target = n-i;

            if(isValid(i) && isValid(target)) return {i,target};
        }

        return {-1,-1};
    }
};