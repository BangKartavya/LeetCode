class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        const int N = 24*60;
        int minX = N;
        int maxX = 0;

        bitset<N> seen = 0;
        for(auto i: timePoints) {
            int x = ((i[0]-'0')*10 + i[1]-'0')*60 + (i[3]-'0')*10 + (i[4]-'0');
            if(seen[x]) return 0;
            seen[x] = 1;
            minX = min(x,minX);
            maxX = max(x,maxX);
        }

        int diff = N;
        int prev = minX;

        for(int x = minX+1;x<=maxX;x++) {
            if(!seen[x]) continue;
            diff = min(diff,x-prev);
            prev = x;
        }
        diff = min(N-(maxX-minX),diff);
        return diff;
    }
};