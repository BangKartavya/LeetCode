class Solution {
public:
    string robotWithString(string s) {
        stack<char> stk;
        int n = s.size();

        int freq[26] = {0};

        for(char& ch: s) freq[ch-'a']++;

        string result;
        
        for(int i = 0;i<n;i++) {
            if(stk.empty()) {

                stk.push(s[i]);
                freq[s[i]-'a']--;

                bool smaller = false;
                
                for(int j = 0;j<s[i]-'a';j++) {
                    if(freq[j] != 0) smaller = true;
                }
                
                if(!smaller) {
                    result.push_back(stk.top());
                    stk.pop();
                }
            }
            else {
                stk.push(s[i]);
                freq[s[i]-'a']--;

                bool smaller = false;
                for(int j = 0;j<stk.top()-'a';j++) {
                    if(freq[j] != 0) smaller = true;
                }

                while(!smaller && !stk.empty()) {
                    result.push_back(stk.top());
                    stk.pop();
                    
                    if(!stk.empty()) {
                        for(int j = 0;j<stk.top()-'a';j++) {
                            if(freq[j] != 0) smaller = true;
                        }
                    }
                }
                
            }
        }

        while(!stk.empty()) {
            result.push_back(stk.top());
            stk.pop();
        }

        return result;
    }
};