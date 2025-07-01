class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int count = 0;

        for(int i = 0;i<n;i++) {
            char ch = word[i];
            int j = i+1;

            while(j < n && word[j] == ch) j++;

            if(j == i+1) continue;

            if(count == 0) count += (j-i);
            else count += (j-i-1);
            i = j-1;
        }

        return count == 0 ? 1 : count;
    }
};