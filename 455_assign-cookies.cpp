class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (g.empty() || s.empty()) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ret = 0;
        for (int i = 0, j = 0; i != g.size() && j != s.size(); ++j) {
            if (g[i] <= s[j]) { ++ret; ++i; }
        }
        return ret;
    }
};
