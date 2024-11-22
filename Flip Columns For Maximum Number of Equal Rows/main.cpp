class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> mp;
        
        for(auto i: matrix) {
            string pat;
            if(i[0] == 0) {
                for(auto j: i) pat += to_string(j);
            }
            else {
                for(auto j: i) pat += to_string(1^j);
            }
            mp[pat]++;
        }
        
        int cnt = 0;
        
        for(auto it : mp) {
            cnt = max(cnt,it.second);
        }
        
        return cnt;
    }
};