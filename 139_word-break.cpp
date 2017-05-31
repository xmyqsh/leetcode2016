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
                for (int i = 0; i != 26; ++i) this->next[i] = NULL;
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
            for (auto ch : s) {
                int idx = ch - 'a';
                if (!cur->next[idx])
                    cur->next[idx] = new TrieNode();
                cur = cur->next[idx];
            }
            cur->have = true;
        }
        bool search(const string& s) {
            TrieNode* cur = root;
            for (auto ch : s) {
                int idx = ch - 'a';
                if (!cur->next[idx]) return false;
                cur = cur->next[idx];
            }
            return cur->have;
        }
    };
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int minLen = INT_MAX, maxLen = 0;
        TrieTree* tree = new TrieTree();
        for (auto& word : wordDict) {
            minLen = min(minLen, (int)word.size());
            maxLen = max(maxLen, (int)word.size());
            tree->insert(word);
        }
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i != s.size() + 1; ++i) {
            for (int j = minLen, pos = i - j; j != maxLen + 1 && pos >= 0; ++j, --pos) {
                if (dp[pos] && tree->search(s.substr(pos, j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
