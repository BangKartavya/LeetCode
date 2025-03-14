class Solution {
private:

    bool isValid(int mid ,long long int k,vector<int> candies) { // can we give mid candy to k kids such that each kid gets same candies
        long long int given = 0;

        for(int i = 0;i<candies.size();i++) {
            given += candies[i]/mid;

            if(given >= k) return true;
        }

        return false;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
    
        long long int sum = accumulate(begin(candies),end(candies),(long long)0);
        int n = candies.size();

        if(sum < k) return 0;

        int maxi = *max_element(begin(candies),end(candies));

        int s = 1;
        int e = maxi;
        int ans = 0;

        while(s <= e) {
            long long int mid = s + (e-s)/2;

            if(isValid(mid,k,candies)) {
                ans = mid;
                s = mid+1;
            }
            else e = mid-1;
        }
        return ans;
    }
};