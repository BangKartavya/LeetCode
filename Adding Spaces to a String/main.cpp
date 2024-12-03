class Solution {
    public:
        string addSpaces(string s, vector<int>& spaces) {
            string ans;

            int n = s.size();
            int m = spaces.size();

            int i = 0;
            int j = 0;

            if(spaces[j] == 0) {
                ans += ' ';
                j++;
            }

            while(i < n && j < m) {
                if(i + 1 == spaces[j]) {
                    ans += s[i];
                    ans += ' ';
                    i++;
                    j++;
                } else {
                    ans += s[i];
                    i++;
                }
            }

            while(i < n)
                ans += s[i++];

            return ans;
        }
};