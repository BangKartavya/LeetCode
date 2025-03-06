class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> freq((n)*(n) + 1,1);
    
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                freq[grid[i][j]]--;
            }
        }

        vector<int> result(2);

        for(int i = 0;i<=(n)*(n);i++) {
            if(freq[i] == -1) result[0] = i;
            else if(freq[i] == 1 && i != 0) result[1] = i;
        }

        return result;

    }
};