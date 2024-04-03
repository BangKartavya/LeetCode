class Solution {
public:
    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,1,-1};
    int n,m;
    vector<vector<char>> _board;
    string _word;

    bool isValid(int r,int c) {
        return (r<0 || r>=n || c<0 || c>=m) ? false : true ;
    }
    bool DFS(int r,int c,int ptr) {
        if(ptr == _word.size()) return true;

        if(!isValid(r,c)|| _board[r][c]=='0' || _word[ptr]!=_board[r][c]) return false;

        char tmp = _board[r][c];
        _board[r][c] = '0';

        for(int i =0;i<4;++i) {
            if(DFS(r+dr[i],c + dc[i],ptr+1)) return true;
        }

        _board[r][c] = tmp;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();
        _board = board;
        _word = word;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (DFS(i, j, 0))
                    return true;
            }
        }
        return false;
    }
};