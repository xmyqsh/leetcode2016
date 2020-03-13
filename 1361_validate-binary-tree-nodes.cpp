class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        if (n == 1) return true;
        unordered_map<int, unordered_set<int>> p2s, s2p;
        for (int i = 0; i != n; ++i) {
            int l = leftChild[i];
            int r = rightChild[i];
            if (l != -1) { p2s[i].insert(l); s2p[l].insert(i); }
            if (r != -1) { p2s[i].insert(r); s2p[r].insert(i); }
        }
        int cntP = 0;
        for (int i = 0; i != n; ++i) {
            if (p2s[i].size() == 0 && s2p[i].size() == 0) {
                return false;
            }
            if (p2s[i].size() > 2) {
                return false;
            }
            if (s2p[i].size() > 1) {
                return false;
            }
            if (s2p[i].size() == 0) ++cntP;
        }
        if (cntP != 1) {
            return false;
        }
        return true;
    }
};
