class Solution {
public:
    struct TrieNode {
        TrieNode* next[2];
        TrieNode() {
            next[0] = next[1] = NULL;
        }
    };
    int findMaximumXOR(vector<int>& nums) {
        tree = new TrieNode();
        for (auto num : nums)
            build(num);
        int result = 0;
        for (auto num : nums)
            result = max(result, calc(num));
        return result;
    }
    void build(int num) {
        TrieNode* cur = tree;
        unsigned int mask = (1 << 31);
        for (int i = 0; i != 32; ++i) {
            int bit = (mask & num) ? 1 : 0;
            if (!cur->next[bit])
                cur->next[bit] = new TrieNode();
            cur = cur->next[bit];
            mask >>= 1;
        }
    }
    int calc(int num) {
        TrieNode* cur = tree;
        unsigned int mask = (1 << 31), result = 0;
        for (int i = 0; i != 32; ++i) {
            int bit = (mask & num) ? 0 : 1;
            if (cur->next[bit]) {
                result |= mask;
                cur = cur->next[bit];
            } else {
                cur = cur->next[bit ? 0 : 1];
            }
            mask >>= 1;
        }
        return result;
    }
private:
    TrieNode* tree;
};

/*
5 = 4 + 1
25 = 16 + 8 + 1

5:  000101
~5: 111010
25: 011001
*/
