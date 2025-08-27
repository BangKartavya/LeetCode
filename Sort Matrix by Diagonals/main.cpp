class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int,priority_queue<int>> maxHeap;
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>> minHeap;
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                int k = i-j;

                if(k < 0) {
                    minHeap[k].push(grid[i][j]);
                }
                else maxHeap[k].push(grid[i][j]);
            }
        }

        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                int k = i-j;

                if(k < 0) {
                    grid[i][j] = minHeap[k].top();
                    minHeap[k].pop();
                }
                else {
                    grid[i][j] = maxHeap[k].top();
                    maxHeap[k].pop();
                }
            }
        }

        return grid;
    }
};