class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> st;
        for (int i = 0; i < board.size(); ++i) {
            st.clear();
            for (int j = 0; j < board[0].size(); ++j)
                if (board[i][j] != '.')
                    if (st.count(board[i][j])) return false;
                    else st.insert(board[i][j]);
        }
        for (int j = 0; j < board[0].size(); ++j) {
            st.clear();
            for (int i = 0; i < board.size(); ++i)
                if (board[i][j] != '.')
                    if (st.count(board[i][j])) return false;
                    else st.insert(board[i][j]);
        }
        for (int m = 0; m < 3; ++m) {
            for (int n = 0; n < 3; ++n) {
                st.clear();
                for (int i = m * 3; i < (m + 1) * 3; ++i)
                    for (int j = n * 3; j < (n + 1) * 3; ++j)
                        if (board[i][j] != '.')
                            if (st.count(board[i][j])) return false;
                            else st.insert(board[i][j]);
            }
        }
        return true;
    }
};
