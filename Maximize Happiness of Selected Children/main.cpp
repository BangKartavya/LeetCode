class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        int n = h.size();
        vector<int> temp;
        long long int ans = 0;
        for(auto i: h) temp.push_back(i);

        sort(temp.begin(),temp.end(),greater<int>());

        long long maxi = 0;
        for(int i =0;i<k;i++) {
            maxi+=max(temp[i]-i,0);
        }
        return maxi;
    }
};