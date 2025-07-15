class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;

        const char vowel[10] = {'a','e','i','o','u','A','E','I','O','U'};
        const char cons[42] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z','B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Y','Z'};

        bool foundV = false;
        bool foundC = false;
        bool foundI = false;

        for(char& ch: word) {
            if(find(vowel,vowel+10,ch) != (vowel+10)) foundV = true;
            if(find(cons,cons+42,ch) != (cons+42)) foundC = true;

            if(!(ch >= '0' && ch <= '9') && !(ch >= 'a' && ch <= 'z') && !(ch >= 'A' && ch <= 'Z')) foundI = true;

        }

        return foundV && foundC && !foundI;
        
    }
};