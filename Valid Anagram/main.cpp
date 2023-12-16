class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        
        map<char,int> mapS;
        map<char,int> mapT;
        
        for(int i =0;i<s.length();i++) {
            mapS[s[i]]++;
            mapT[t[i]]++;
        } 
        
        for(auto i : mapS) {
            if(mapT.find(i.first)==mapT.end()) return false;
            else {
                if(mapT[i.first]!=i.second) return false;
            }
            
        }
        return true;
        
    }
};