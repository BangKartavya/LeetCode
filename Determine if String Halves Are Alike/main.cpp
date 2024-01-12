class Solution {
public:
    bool halvesAreAlike(string s) {
        string a = s.substr(0,s.size()/2);
        string b = s.substr(s.size()/2,s.size()-1);
        
        char vowel[10] = {'a','e','i','o','u','A','E','I','O','U'};
        
        int vA = 0;
        int vB = 0;
        
        for(int i =0;i<a.size();i++) {
            for(int j =0;j<10;j++) {
                if(a[i]==vowel[j]) vA++;
                if(b[i]==vowel[j]) vB++;
            }
        }
        
        if(vA==vB) return true;
        return false;
    }
};