class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
     
        long long int abs_sum = 0;
        long long int neg = 0;
        int mini = INT_MAX;
        
        int n = matrix.size();
        
        bool zero_found = false;
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                mini = min(mini,abs(matrix[i][j]));
                if(matrix[i][j] < 0) {
                    neg++;
                    abs_sum += abs(matrix[i][j]);
                }
                else if(matrix[i][j] == 0) zero_found = true;
                else abs_sum += matrix[i][j];
            }
        }
        if(neg%2 == 0 || zero_found) return abs_sum;
                
        return abs_sum - 2*mini;
    }
};