class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> v(26,0);
        for(auto j: allowed) v[j-'a']++;
        
        bool valid = true;
        int cnt = 0;
        
        for(auto i: words) {
            for(auto j: i) {
                if(v[j-'a'] == 0) {
                    valid = false;
                    break;
                }
            }
            if(valid) cnt++;
            valid = true;
        }
        return cnt;
    }
};