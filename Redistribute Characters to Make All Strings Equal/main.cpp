class Solution {
public:
    bool makeEqual(vector<string>& words) {
        if(words.size()==1) return true;
        
        int total = 0;
        
        for(auto s:words) total+=s.length();
        
        if(total%words.size()!=0) return false;
        
        vector<int> myMap(26,0);
        
        for(auto s:words) for(auto c: s) myMap[c-'a']++;
        
        for(auto i:myMap) if(i%words.size()!=0) return false;
        
        return true;
    }
};