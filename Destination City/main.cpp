class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> s;
        
        for(auto i : paths) s.insert(i[0]);
        
        for(auto i: paths) {
            string dest = i[1];
            
            if(s.find(dest)==s.end()) return dest;
        }
        
        return "";
        
    }
};