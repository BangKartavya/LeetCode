class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int n = blocks.size();

            int s = 0;
            int e = k;

            int mini = INT_MAX;

            while(e <= n) {
                int cnt = 0;

                for(int i = s; i < e; i++) {
                    if(blocks[i] == 'W') cnt++;
                }

                mini = min(mini, cnt);
                s++;
                e++;
            }

            return mini;
        }
};
