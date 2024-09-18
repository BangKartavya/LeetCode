class Solution {
public:
    vector<int> dp[20][20];
    vector<int> convert(string& expression) {
        vector<int> ans;
        int sz = expression.size();
        ans.reserve(sz);
        int x = 0;
        for(int i =0;i<sz;i++) {
            const char c = expression[i];
            switch(c) {
                case '+': 
                ans.push_back(101);
                break;
                case '-':
                ans.push_back(102);
                break;
                case '*':
                ans.push_back(103);
                break;

                default: {
                    x = 10*x+c -'0';
                    if(i == sz-1 || !isdigit(expression[i+1])) {
                        ans.push_back(x);
                        x = 0;
                    }
                }
            }
        }
        return ans;
    }
    vector<int> f(int l,int r,vector<int>& nums) {
        if(l > r) return {};
        if(l == r) {
            if(nums[l] >= 101) return {};
            return {nums[l]};
        }

        if(dp[l][r].size() > 0) return dp[l][r];

        vector<int> ans;

        for(int i = l;i<=r;i++) {
            if(nums[i] < 100) continue;

            vector<int> left = f(l,i-1,nums);
            vector<int> right = f(i+1,r,nums);

            for(int lef : left) {
                for(int rig : right) {
                    int x = 0;
                    switch(nums[i]) {
                        case 101: 
                        ans.push_back(lef+rig);
                        break;
                        case 102:
                        ans.push_back(lef-rig);
                        break;
                        case 103:
                        ans.push_back(lef*rig);
                        break;
                    }
                }
            }
        }
        return dp[l][r] = ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int> nums = convert(expression);
        const int n = nums.size();
        return f(0,n-1,nums);
    }
};