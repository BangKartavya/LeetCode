class Solution {
public:
    int findComplement(int num) {
        string bin;

        while(num > 0) {
            if(num%2) {
                bin+='0';
                num/=2;
            }
            else {
                bin+='1';
                num/=2;
            }
        }

        reverse(bin.begin(),bin.end());

        int p = bin.size() -1;
        int a = 0;

        for(auto i: bin) {
            a += (int)pow(2,p--)*(i-'0');
        }
        
        return a;

    }
};