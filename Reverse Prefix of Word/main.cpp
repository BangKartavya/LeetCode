class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        for(int i =0;i<word.size();i++) {
            if(ch==word[i] && i!=0) {
                string f = word.substr(0,i+1);
                string e = word.substr(i+1,word.size()-f.size());
                reverse(f.begin(),f.end());
                return f+e;
            }
            if(ch==word[i] && i==0) return word;
        }
        return word;
    }
};