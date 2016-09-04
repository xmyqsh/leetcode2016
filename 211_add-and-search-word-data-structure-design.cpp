class WordDictionary {
private:
    class TrieNode {
    public:
        TrieNode() {
            for (int i = 0; i < 26; ++i) next[i] = 0;
            have = false;
        }
    public:
        TrieNode* next[26];
        bool have;
    };
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* cur = root;
        for (auto ch : word) {
            const int c = ch - 'a';
            if (!cur->next[c]) cur->next[c] = new TrieNode();
            cur = cur->next[c];
        }
        cur->have = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(word, root);
    }

    bool search(string word, TrieNode* root) {
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] == '.') {
                for (int k = 0; k < 26; ++k)
                    if (root->next[k] && search(word.substr(i + 1, word.size() - i - 1), root->next[k]))
                        return true;
                return false;
            } else {
                const int c = word[i] - 'a';
                if (!root->next[c]) return false;
                root = root->next[c];
            }
        }
        return root->have;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
