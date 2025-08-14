class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        int i = 0;
        int j = 2;

        int freq[10];
        memset(freq,0,sizeof(freq));
        
        string res;

        for(int k = i;k<j;k++) freq[num[k]-'0']++;

        while(j < n) {
            freq[num[j]-'0']++;
            bool uniq = true;
            for(int k = 0;k<10;k++) if(freq[k] > 0 && freq[k] != 3) uniq = false;

            if(uniq) res = max(res,num.substr(i,3));

            j++;
            freq[num[i]-'0']--;
            i++;
        }

        return res;
    }
};