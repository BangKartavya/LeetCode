class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,priority_queue<int>>mpp;
        for(int &num:nums) {
            int cur = num;
            int sum=0;
            while(cur) {
                sum+=(cur%10);
                cur/=10;
            }
            mpp[sum].push(num);
        }
        int ans=-1;
        for(auto& it: mpp) {
            if(it.second.size()>1) {
                int sum=0;
                for(int i=0;i<2;++i) {
                    sum+=it.second.top();
                    it.second.pop();
                }
                ans=max(ans,sum);
            }
        }
        return ans;
    }
};