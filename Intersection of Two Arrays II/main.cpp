class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        map<int,int> mp1;
        map<int,int> mp2;

        for(auto i: nums1) mp1[i]++;
        for(auto i: nums2) mp2[i]++;

        for(auto it: mp1) {
            if(mp2.find(it.first)!=mp2.end()) {
                if(mp2[it.first]<it.second) {
                    for(int j = 0;j<mp2[it.first];j++) ans.push_back(it.first);
                }
                else {
                    for(int j =0;j<it.second;j++) ans.push_back(it.first);
                }
            }
        }


        return ans;

    }
};