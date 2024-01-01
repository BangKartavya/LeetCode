class Solution {
public
    int findContentChildren(vectorint& g, vectorint& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int i =0;
        
        for(int j=0;js.size() && ig.size();j++) {
            if(g[i]=s[j]) i++;
        }
        return i;
    }
};