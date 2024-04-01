class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        bool flag = false;
        
        for(int i = s.size()-1;i>=0;i--) {
            if(s[i]==' ' && flag) break;
            if(s[i]!=' ') {
                count++;
                flag = true;
            }
        }
        
        return count;
    }
};