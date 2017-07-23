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
        string search(const string& s) {
            TrieNode* cur = root;
            for (int i = 0; i != s.size(); ++i) {
                int idx = s[i] - 'a';
                if (!cur->next[idx]) break;
                cur = cur->next[idx];
                if (cur->have) return s.substr(0, i + 1);
            }
            return s;
        }
    };
public:
    string replaceWords(vector<string>& dict, string sentence) {
        TrieTree* tree = new TrieTree();
        for (auto root : dict) tree->insert(root);
        stringstream ss;
        int b = sentence.find_first_not_of(' ', 0), e;
        if (b == string::npos) b = sentence.size();
        ss << sentence.substr(0, b);
        for (; b != sentence.size(); ) {
            e = sentence.find_first_of(' ', b);
            if (e == string::npos) e = sentence.size();
            ss << tree->search(sentence.substr(b, e - b));
            if (e == sentence.size()) break;
            b = sentence.find_first_not_of(' ', e);
            if (b == string::npos) b = sentence.size();
            ss << sentence.substr(e, b - e);
            if (b == sentence.size()) break;
        }
        return ss.str();
    }
};
