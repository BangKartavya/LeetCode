class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
        

        int ans=0;
        
        for(auto j: nums) mp[j]++;
        
       
        
        for(auto i: mp) {
            int t = i.second;
            
            if(t==1) return -1;
            
            ans+=t/3;
            
            if(t%3) ans++;
        }
        
        return ans;
    }
};