class Solution {
private:
    vector<string> words(string sentence) {
        vector<string> res;
        string temp;

        for(auto i: sentence) {
            if(i == ' ') {
                res.push_back(temp);
                temp = "";
            }

            else temp += i; 
        }

        res.push_back(temp);

        return res;
    }
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> w = words(sentence);
        int n = w.size();
        int m = searchWord.size();

        for(int i = 0;i<n;i++) {
            int j = 0;
            if(w[i].size() < m) continue;

            while(j < m) {
                if(w[i][j] == searchWord[j]) {
                    j++;
                }
                else {
                    break;
                }
            }
            if(j == m) return i+1;
        }

        return -1;
    }
};