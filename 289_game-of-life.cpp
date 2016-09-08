class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty()) return;
        for (int i = 0; i != board.size(); ++i) {
            for (int j = 0; j != board[0].size(); ++j) {
                update(board, i, j, i, j + 1);
                update(board, i, j, i + 1, j - 1);
                update(board, i, j, i + 1, j);
                update(board, i, j, i + 1, j + 1);
                if (board[i][j] >= 5 && board[i][j] <= 7) board[i][j] = 1;
                else board[i][j] = 0;
            }
        }
    }
    void update(vector<vector<int> >& board, int i, int j, int a, int b) {
        if (a == board.size() || b == -1 || b == board[0].size()) return;
        if (board[i][j] % 2) board[a][b] += 2;
        if (board[a][b] % 2) board[i][j] += 2;
    }
};
