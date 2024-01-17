class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp;
        vector<int> vp;
        set<int> s;
        
        for(auto i: arr) mp[i]++;
        
        for(auto i:mp) {
            vp.push_back(i.second);
            s.insert(i.second);
        }
        
        if(vp.size()==s.size()) return true;
        
        return false;
    }
};