class Solution {
public:
    int findMinStep(string board, string hand) {
        unordered_map<char, int> mp;
        for (auto ch : hand) ++mp[ch];
        int result = hand.size() + 1;
        dfs(board, mp, 0, result);
        return result == hand.size() + 1 ? -1 : result;
    }
    void dfs(string board, unordered_map<char, int> mp, int used, int& result) {
        if (board.empty()) {
            result = min(result, used);
            return;
        }
        if (mp.empty()) return;
        for (int i = 1; i != board.size(); ++i) {
            if (board[i] == board[i - 1]) {
                if (!mp.count(board[i])) continue;
                if (--mp[board[i]] == 0) mp.erase(board[i]);
                string newBoard = board.substr(0, i - 1) + board.substr(i + 1);
                shorten(newBoard, i - 2);
                dfs(newBoard, mp, used + 1, result);
                ++mp[board[i]];
            } else if (i == 1 || board[i - 2] != board[i - 1]) {
                if (!mp.count(board[i - 1]) || mp[board[i - 1]] < 2) continue;
                if ((mp[board[i - 1]] -= 2) == 0) mp.erase(board[i - 1]);
                string newBoard = board.substr(0, i - 1) + board.substr(i);
                if (i != 1) shorten(newBoard, i - 2);
                dfs(newBoard, mp, used + 2, result);
                mp[board[i - 1]] += 2;
            }
        }
        int idx = board.size() - 1;
        if (board.size() == 1 || board[idx - 1] != board[idx]) {
            if (mp.count(board[idx]) && mp[board[idx]] >= 2) {
                if ((mp[board[idx]] -= 2) == 0) mp.erase(board[idx]);
                dfs(board.substr(0, idx), mp, used + 2, result);
                mp[board[idx]] += 2;
            }
        }
    }
    void shorten(string& board, int idx) {
        int left = idx, right = idx + 1;
        while (left != -1 && board[left] == board[idx + 1]) --left;
        while (right != board.size() && board[right] == board[idx]) ++right;
        if (right - left - 1 > 2) {
            board = board.substr(0, left + 1) + board.substr(right);
            shorten(board, left);
        }
    }
};
