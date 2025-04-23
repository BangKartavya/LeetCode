class Solution {
    public:
        int countLargestGroup(int n) {
            unordered_map<int, int> mp;

            for(int i = 1; i <= n; i++) {
                int sum = 0;
                int key = i;

                while(key > 0) {
                    sum += key % 10;
                    key /= 10;
                }

                mp[sum]++;
            }

            int result = 0;
            int siz = 0;

            vector<int> vp(1e4, 0);
            for(auto it : mp) {
                vp[it.second]++;
            }

            for(int i = 1; i < 1e4; i++) {
                if(i > siz && vp[i] != 0) {
                    result = vp[i];
                    siz = i;
                } else result = max(result, vp[i]);
            }
            return result;
        }
};