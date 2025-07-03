class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";

        while(word.size() <= k) {
            string next = word;

            for(int i = 0;i<next.size();i++) {
                next[i] = (next[i]-'a'+1)%26 +'a';
            }

            word += next;
        }

        return word[k-1];
    }
};