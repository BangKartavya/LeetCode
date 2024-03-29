class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
       int n = nums1.size();
       int m = nums2.size();

       int i = 0;
       int j = 0;

        int ans = INT_MAX;

       while(i<n && j<m) {
           if(nums1[i]==nums2[j]) {
               ans = nums1[i];
               break;
           }
           else if(nums1[i]<nums2[j]) i++;
           else if(nums1[i]>nums2[j]) j++;
       }
       return ans==INT_MAX ? -1 : ans;

    }
};