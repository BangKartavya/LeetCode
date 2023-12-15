class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<vector<int>> diff(grid.size(),vector<int>(grid[0].size(),1));
        
        vector<int> oneR(grid.size(),0);
        vector<int> oneC(grid[0].size(),0);
        
        vector<int> zeroR(grid.size(),0);
        vector<int> zeroC(grid[0].size(),0);
        
        for(int i =0;i<grid.size();i++) {
            for(int j = 0;j<grid[i].size();j++) {
               if(grid[i][j]==1) {
                   oneR[i]++;
                   oneC[j]++;
                  }
                else {
                    zeroR[i]++;
                    zeroC[j]++;
                   }
               }
           }
        for(int i = 0;i<grid.size();i++) {
            for(int j = 0;j<grid[i].size();j++) {
                diff[i][j] = oneR[i] + oneC[j] - zeroR[i] - zeroC[j];
               }
           }
        return diff;

            
        
    }
};