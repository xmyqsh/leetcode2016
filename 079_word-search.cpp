class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int> > available(board.size(), vector<int>(board[0].size(), 1));
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                if (travel(board, available, word, i, j, 0))
                    return true;
        return false;
    }
    bool travel(const vector<vector<char> >& board, vector<vector<int> >& available, const string& word, int i, int j, int k) {
        if (k == word.size()) return true;
        if (i < 0 || j < 0 || i == board.size() || j == board[0].size()) return false;
        if (!available[i][j] || board[i][j] != word[k]) return false;
        available[i][j] = 0;
        
        bool ret = travel(board, available, word, i - 1, j, k + 1) ||
                    travel(board, available, word, i, j - 1, k + 1) ||
                    travel(board, available, word, i + 1, j, k + 1) ||
                    travel(board, available, word, i, j + 1, k + 1);
        available[i][j] = 1;
        return ret;
    }
};
