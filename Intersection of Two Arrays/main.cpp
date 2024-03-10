class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        for(auto i: nums1) {
            if(find(nums2.begin(),nums2.end(),i)==nums2.end()) continue;
            if(find(nums2.begin(),nums2.end(),i)!= nums2.end() && find(ans.begin(),ans.end(),i)==ans.end()) ans.push_back(i);
            else continue;
        }
        return ans;
    }
};