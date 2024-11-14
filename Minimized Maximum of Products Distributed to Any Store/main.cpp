class Solution {
public:
    bool helper(int x, vector<int>& quantities,int& n) {
        int sum = 0;
        
        for(auto a: quantities) {
            sum += (a+x-1)/x;
        }
        
        return sum > n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int s= 1;       
        int r = 100000;
        
        while(s < r) {
            int mid = s + (r-s)/2;
            
            if(helper(mid,quantities,n)) s = mid+1;
            else r = mid;
        }
        return s;
    }
};