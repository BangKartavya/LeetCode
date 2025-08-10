class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string dig = to_string(n);

        string pow2 = "1";

        while(pow2.size() <= dig.size()) {
            if(pow2.size() == dig.size()) {
                int freq[10];
                memset(freq,0,sizeof(freq));

                for(char& ch: dig) freq[ch-'0']++;
                for(char& ch: pow2) freq[ch-'0']--;
                bool found = true;
                for(int i = 0;i<10;i++) if(freq[i] != 0) found = false;

                if(found) return true;
            }
            long long int num = stol(pow2);
            num *= 2;
            pow2 = to_string(num);

        }
        return false;
    }
};