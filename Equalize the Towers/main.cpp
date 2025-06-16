class Solution {
  private:
    vector<int> heights;
    vector<int> cost;
    int n;
    
    int getCost(int mid) {
        int c = 0;
        
        for(int i = 0;i<n;i++) {
            c += abs(heights[i]-mid) * cost[i];
        }
        
        return c;
    }
    
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        n = heights.size();
        this->heights = heights;
        this->cost = cost;
        
        int s = 0;
        int e = *max_element(begin(heights),end(heights));
        int ans = INT_MAX;
        
        while(s <= e) {
            int mid = s + (e-s)/2;
            int costMid = getCost(mid);
            int costPrev = getCost(mid-1);
            int costNext = getCost(mid+1);
            
            if(costMid <= costPrev && costMid <= costNext) {
                return costMid;
            }
            else if(costMid <= costPrev && costMid > costNext) {
                s = mid+1;
            }
            else e = mid - 1;
        }
        
        return ans;
        
    }
};
