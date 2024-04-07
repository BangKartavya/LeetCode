class Solution {
public:
    bool checkValidString(string s) {
        if(s[0]==')') return false;

        int lC = 0;
        int rC = 0;

        for(auto c: s) {
            lC += c=='(' ? 1: -1; 
            rC += c==')' ? -1: 1; 

            if(rC<0) break;
            lC = max(lC,0);
        }
        

        return lC==0;

        
    }
};