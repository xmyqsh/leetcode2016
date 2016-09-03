class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        for (int i = 0; i < 26; ++i) next[i] = 0;
        have = false;
    }
public:
    bool have;
    TrieNode* next[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); ++i) {
            const int c = word[i] - 'a';
            if (!cur->next[c]) cur->next[c] = new TrieNode();
            cur = cur->next[c];
        }
        cur->have = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); ++i) {
            const int c = word[i] - 'a';
            if (!cur->next[c]) return false;
            cur = cur->next[c];
        }
        return cur->have;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (int i = 0; i < prefix.size(); ++i) {
            const int c = prefix[i] - 'a';
            if (!cur->next[c]) return false;
            cur = cur->next[c];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
