bool cmp(pair<int,int> p1,pair<int,int> p2) {
    return p1.second<p2.second;
}
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> mp;

        for(auto i : arr) mp[i]++;

        vector<pair<int,int>> vp;

        for(auto it: mp) vp.push_back({it.first,it.second});

        sort(vp.begin(),vp.end(),cmp);
        
        int unique = vp.size();
        
        for(auto i: vp) {
            if(k>=i.second) {
                k-=i.second;
                unique--;
            }
            else break;
        }
        return unique;
    }
};