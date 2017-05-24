class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solver(board);
    }
    bool solver(vector<vector<char> >& board) {
        for (int i = 0; i != 9; ++i) {
            for (int j = 0; j != 9; ++j) {
                if (board[i][j] == '.') {
                    unordered_set<char> st = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
                    for (int k = 0; k != 9; ++k) {
                        st.erase(board[i][k]);
                        st.erase(board[k][j]);
                    }
                    int row = i / 3 * 3, col = j / 3 * 3;
                    for (int p = 0; p != 3; ++p)
                        for (int q = 0; q != 3; ++q)
                            st.erase(board[row + p][col + q]);
                    for (auto elem : st) {
                        board[i][j] = elem;
                        if (solver(board)) return true;
                    }
                    board[i][j] = '.';
                    return false;
                }
            }
        }
        return true;
    }
};
