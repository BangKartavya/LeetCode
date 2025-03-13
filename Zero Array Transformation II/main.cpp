class Solution {
public:
    int n;
    bool valid(vector<int>& nums,int mid,vector<vector<int>>& queries) {
        
        int cnt = 0;
        
        vector<pair<int,int>> freq(n+1);
        
        for(int i = 0;i<mid;i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            
            freq[l].first++;
            freq[l].second+=val;
            freq[r+1].first--;
            freq[r+1].second-=val;
        }
        
        for(int i = 1;i<=n;i++) {
            freq[i].first += freq[i-1].first;
            freq[i].second += freq[i-1].second;
        }
        
        for(int i = 0;i<n;i++) {
            if(nums[i] > freq[i].second) return false;
        }
        
        return true;
        
    }
    
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        int m = queries.size();
        int s = 0;
        int e = m-1;
        while(s<=e) {
            int mid = s + (e-s)/2;
            bool isValid = valid(nums,mid,queries);
            if(isValid) {
                e = mid-1;
            }
            else {
                s = mid+1;
            }
        }
        
        return valid(nums,s,queries) ? s : -1;
    }
};