class Solution {
    private:
        int GCD(int x, int y) {
            if(y == 0) return x;

            return GCD(y, x % y);
        }

        int LCM(int x, int y) {
            long long prod = (long long)x * (long long)y;

            return prod / GCD(x, y);
        }

    public:
        vector<int> replaceNonCoprimes(vector<int>& nums) {
            vector<int> stk;

            for(int& i : nums) {
                if(stk.empty()) stk.push_back(i);
                else {
                    int toAdd = i;
                    while(!stk.empty() && GCD(stk.back(), toAdd) > 1) {
                        toAdd = LCM(stk.back(), toAdd);
                        stk.pop_back();
                    }

                    stk.push_back(toAdd);
                }
            }

            return stk;
        }
};