class Solution {
    public:
        int minOperations(vector<int>& nums) {
            stack<int> stk;
            int res = 0;

            for(int& x : nums) {
                while(!stk.empty() && x < stk.top())
                    stk.pop();

                if(stk.empty() || x > stk.top()) {
                    if(x > 0) res++;
                    stk.push(x);
                }
            }

            return res;
        }
};