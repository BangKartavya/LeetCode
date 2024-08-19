class Solution {
public:
    int targetLength;

    int findMinSteps(int curr,int clip) {
        if(curr == targetLength) return 0;
        if(curr > targetLength) return INT_MAX/2;

        int copy = 2 + findMinSteps(curr*2,curr);
        int paste = 1 + findMinSteps(curr + clip,clip);

        return min(copy,paste);
    }
    int minSteps(int n) {
        if(n == 1) return 0;
        targetLength = n;
        return 1 + findMinSteps(1,1);

    }
};