class Solution {
public:
    int m;
    int n;
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        m = box.size();
        n = box[0].size();
        
        vector<vector<char>> transpose(n,vector<char>(m));
        
        for(int j = 0;j<n;j++) {
            for(int i  =0;i<m;i++) {
                transpose[j][i] = box[i][j];
            }
        }
        
        for(int j = 0;j<m/2;j++) {
            for(int i = 0;i<n;i++) {
                swap(transpose[i][j],transpose[i][m-j-1]);
            }
        }
        
        for(int i = n-1;i>=0;i--) {
            for(int j = 0;j<m;j++) {
                if(transpose[i][j] == '#') {
                    int k = i+1;
                    
                    while(k < n && (transpose[k][j] != '*' && transpose[k][j] != '#')) {
                        k++;
                    }
                    transpose[i][j] = '.';
                    transpose[k-1][j] = '#';
                    
                }
            }
        }
        
        return transpose;
    }
};