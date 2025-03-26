class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> result;

        for(vector<int>& row: grid) {
            for(int& i: row) {
                result.push_back(i);
            }
        }

        sort(begin(result),end(result));

        int n = grid.size() * grid[0].size();
        int median = result[n/2];
        int steps = 0;

        for(int i = 0;i<n;i++) {
            if(abs(result[i]-median) % x == 0) {
                steps += abs(result[i]-median)/x;
            }
            else {
                return -1;
            }
        }

        return steps;

    }
};