class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        for (int i = 0; i < board.size(); ++i) {
            dfs(board, i, 0);
            dfs(board, i, board[0].size() - 1);
        }
        for (int j = 1; j < board[0].size() - 1; ++j) {
            dfs(board, 0, j);
            dfs(board, board.size() - 1, j);
        }
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                if (board[i][j] == '#') board[i][j] = 'O';
                else board[i][j] = 'X';
    }
    void dfs(vector<vector<char> >& board, int i, int j) {
        if (board[i][j] != 'O') return;
        board[i][j] = '#';
        if (i > 1) dfs(board, i - 1, j);
        if (i + 2 < board.size()) dfs(board, i + 1, j);
        if (j > 1) dfs(board, i, j - 1);
        if (j + 2 < board[0].size()) dfs(board, i, j + 1);
    }
};
