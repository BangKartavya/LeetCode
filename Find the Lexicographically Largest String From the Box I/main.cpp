class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1) return word;
        
        int n = word.size();
        string res;

        for(int i = 0;i<n;i++) {
            res = max(res,word.substr(i,word.size()-numFriends+1));
        }

        return res;
    }
};