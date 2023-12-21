class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> xi;
        
        for(auto i: points) xi.push_back(i[0]);
        
        sort(xi.begin(),xi.end());
        
        int maxWid = 0;
        
        for(int i=0;i<xi.size()-1;i++) {
            if((xi[i+1]-xi[i])>maxWid) maxWid = xi[i+1]-xi[i];
        }
        return maxWid;
    }
};