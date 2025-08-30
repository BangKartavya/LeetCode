class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int n = 9;

        // cols
        for(int i = 0;i<n;i++) {
            int freq[10] = {0};

            for(int j = 0;j<n;j++) {
                if(isdigit(board[i][j]))
                    freq[board[i][j]-'0']++;
            }

            for(int j = 0;j<10;j++) if(freq[j] > 1) return false;
        }

        //rows
        for(int j = 0;j<n;j++) {
            int freq[10] = {0};

            for(int i = 0;i<n;i++) {
                if(isdigit(board[i][j]))
                    freq[board[i][j]-'0']++;
            }

            for(int i = 0;i<10;i++) if(freq[i] > 1) return false;
        }

        //3x3 mini

        for(int i = 0;i<n;i+=3) {
            for(int j = 0;j<n;j+=3) {
                int freq[10] = {0};
                for(int k = i;k<i+3;k++) {
                    for(int l = j;l<j+3;l++) {
                        if(isdigit(board[k][l]))
                            freq[board[k][l]-'0']++;
                    }
                }
                for(int z = 0;z<10;z++) if(freq[z] > 1) return false;
            }
        }

        return true;
    }
};