class Solution {
private:
    class TrieTree {
    private:
        class TrieNode {
        public:
            TrieNode* next[26];
            bool have;
        public:
            TrieNode() {
                for (int i = 0; i != 26; ++i)
                    this->next[i] = NULL;
                this->have = false;
            }
        };
    private:
        TrieNode* root;
    public:
        TrieTree() {
            this->root = new TrieNode();
        }
        void insert(const string& s) {
            TrieNode* cur = root;
            for (auto c : s) {
                int idx = c - 'a';
                if (!cur->next[idx])
                    cur->next[idx] = new TrieNode();
                cur = cur->next[idx];
            }
            cur->have = true;
        }
        bool search(const string& s) {
            TrieNode* cur = root;
            for (auto c : s) {
                int idx = c - 'a';
                if (!cur->next[idx]) return false;
                cur = cur->next[idx];
            }
            return cur->have;
        }
    };
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        TrieTree* tree = new TrieTree();
        int minLen = INT_MAX, maxLen = 0;
        for (auto& word : wordDict) {
            minLen = min(minLen, (int)word.size());
            maxLen = max(maxLen, (int)word.size());
            tree->insert(word);
        }
        vector<bool> dp(s.size() + 1, false);
        vector<vector<bool> > wordPos(s.size(), vector<bool>(maxLen + 1, false));
        dp[0] = true;
        for (int i = 1; i != s.size() + 1; ++i) {
            for (int j = minLen, pos = i - j; j != maxLen + 1 && pos >= 0; ++j, --pos) {
                if (dp[pos] && tree->search(s.substr(pos, j))) {
                    dp[i] = true;
                    wordPos[pos][j] = true;
                }
            }
        }
        vector<string> result;
        if (!dp[s.size()]) return result;
        vector<string> path;
        genPath(result, path, wordPos, s, 0, minLen, maxLen);
        return result;
    }
    void genPath(vector<string>& result, vector<string>& path, const vector<vector<bool> >& wordPos,
                    const string& s, int cur, int minLen, int maxLen) {
        if (cur == s.size()) {
            stringstream ss;
            for (int i = 0; i != path.size() - 1; ++i) ss << path[i] << ' ';
            ss << path[path.size() - 1];
            result.push_back(ss.str());
            return;
        }
        for (int j = minLen; j != maxLen + 1; ++j) {
            if (wordPos[cur][j]) {
                path.push_back(s.substr(cur, j));
                genPath(result, path, wordPos, s, cur + j, minLen, maxLen);
                path.pop_back();
            }
        }
    }
};
