class Solution {
public:
    int largestCombination(vector<int>& can) {
        int n = can.size();
        int ans = INT_MIN;
        
        for(int i = 0;i<32;i++) {
            int cnt = 0;
            
            for(int j = 0;j<n;j++) {
                if( ( can[j] & ( 1 << i ) ) ) cnt++;
            }
            ans = max(ans,cnt);
        }
        
        return ans;
    }
};