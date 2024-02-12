class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int elem = 0;
        int cnt = 0;

        for(auto i: nums) {
            if(cnt==0) {
                elem = i;
                cnt=1;
            }
            else if(elem == i) cnt++;
            else cnt--;
        }
        return elem;

    }
};