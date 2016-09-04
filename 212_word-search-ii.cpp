class Solution {
private:
    class TrieTree {
    public:
        class TrieNode {
        public:
            TrieNode* next[26];
            int idx;
            bool have;
        public:
            TrieNode() {
                for (int i = 0; i < 26; ++i) next[i] = 0;
                have = false;
            }
        };
        TrieNode* root;
    public:
        TrieTree() {
            root = new TrieNode();
        }
        void addWord(const vector<string>& words, int idx) {
            TrieNode* cur = root;
            for (auto ch : words[idx]) {
                const int c = ch - 'a';
                if (!cur->next[c]) cur->next[c] = new TrieNode();
                cur = cur->next[c];
            }
            cur->have = true;
            cur->idx = idx;
        }
    };
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieTree* trie = new TrieTree();
        for (int i = 0; i < words.size(); ++i) trie->addWord(words, i);
        vector<string> result;
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                dfs(&result, board, words, i, j, trie->root);
        return result;
    }
    void dfs(vector<string>* result, vector<vector<char> >& board, const vector<string>& words, int i, int j,
            TrieTree::TrieNode* cur) {
        if (board[i][j] == 'X') return;
        const int c = board[i][j] - 'a';
        if (!cur->next[c]) return;
        if (cur->next[c]->have) {
            result->push_back(words[cur->next[c]->idx]);
            cur->next[c]->have = false;         // set it false against for multi-match
            //return;                           // trie tree, may not over yet
        }
        char tmp = board[i][j];
        board[i][j] = 'X';
        if (i > 0) dfs(result, board, words, i - 1, j, cur->next[c]);
        if (j > 0) dfs(result, board, words, i, j - 1, cur->next[c]);
        if (i + 1 < board.size()) dfs(result, board, words, i + 1, j, cur->next[c]);
        if (j + 1 < board[0].size()) dfs(result, board, words, i, j + 1, cur->next[c]);
        board[i][j] = tmp;
    }
};
