class Solution {
    private:
        vector<string> split(string text) {
            string temp;
            vector<string> result;

            for(char& ch : text) {
                if(ch == ' ') {
                    result.push_back(temp);
                    temp = "";
                } else temp += ch;
            }

            if(temp.size() > 0) result.push_back(temp);

            return result;
        }

    public:
        int canBeTypedWords(string text, string brokenLetters) {
            vector<string> res = split(text);

            int wordCount = 0;

            for(string& word : res) {
                bool valid = true;
                for(char& ch : word) {
                    if(brokenLetters.find(ch) != string::npos) {
                        valid = false;
                        break;
                    }
                }

                wordCount += valid;
            }

            return wordCount;
        }
};