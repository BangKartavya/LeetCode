class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        map<int,int> mp;

        for(auto i: bills) {
            if(i == 5) mp[i]++;
            else if(i == 10) {
                if(mp[5] > 0) {
                    mp[5]--;
                    mp[i]++;
                }
                else return false;
            }
            else {
                if(mp[10] > 0 && mp[5] > 0) {
                    mp[i]++;
                    mp[10]--;
                    mp[5]--;
                }
                else if (mp[5] >= 3) {
                    mp[5] -= 3;
                    mp[i]++;
                }
                else return false;
            }
        }
        return true;
    }
};