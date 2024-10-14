class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) 
    {
        priority_queue<int>pq;
        for(auto val:nums) 
            pq.push(val);
        
        long long ans = 0, val;
        while(k--)
        {
            val = pq.top(); pq.pop();
            ans += val;
            pq.push(ceil(double(val/3.0)));
        }
        return ans;
    }
};