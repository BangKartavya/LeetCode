class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int> mp;
        int notFound = 0;
        int found = 0;

        for(auto i: nums) mp[i]++;

        for(int i =1;i<nums.size()+1;i++) {
            if(mp.find(i)==mp.end()) notFound=i;
            if(mp[i]==2) found=i;
        }
        return {found,notFound};
    }
};