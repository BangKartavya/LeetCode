class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        
        long long total = 0;
        for(auto i: chalk) total += i;

        int rem = k % total;

        for(int i =0;i<chalk.size(); i++) {
            if(rem < chalk[i] ) return i;
            rem -= chalk[i];
        }

        return 0;

    }
};