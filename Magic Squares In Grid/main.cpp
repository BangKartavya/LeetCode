class Solution {
public:
    bool check(vector<vector<int>>& grid, int x, int y){
        vector<bool> vec(10, false);
        for(int i=x; i<x+3; i++){
            for(int j=y; j<y+3; j++){
                int num = grid[i][j];
                if (num < 1 || num > 9 || vec[num]) {
                    return false;
                }
                vec[num] = true;
            }
        }
        return true;
    }

    bool help(vector<vector<int>>& grid, int m, int v){
        if(!check(grid, m, v)){
            return false;
        }

        int sum = grid[m][v] + grid[m][v+1] + grid[m][v+2];

        for(int i = 0; i < 3; i++){
            int rowSum = grid[m+i][v] + grid[m+i][v+1] + grid[m+i][v+2];
            if(rowSum != sum){
                return false;
            }
        }

        for(int j = 0; j < 3; j++){
            int colSum = grid[m][v+j] + grid[m+1][v+j] + grid[m+2][v+j];
            if(colSum != sum){
                return false;
            }
        }

        int diag1 = grid[m][v] + grid[m+1][v+1] + grid[m+2][v+2];
        int diag2 = grid[m][v+2] + grid[m+1][v+1] + grid[m+2][v];

        if(diag1 != sum || diag2 != sum){
            return false;
        }

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;

        for(int i = 0; i <= r - 3; i++){
            for(int j = 0; j <= c - 3; j++){
                if(help(grid, i, j)){
                    ans++;
                }
            }
        }

        return ans;
    }
};