class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> f(s.size(), 0);
        int ret = 0;
        for (int i = 1; i < s.size(); ++i) {
            int match = i - f[i - 1] - 1;
            if (s[i] == ')' && match >= 0 && s[match] == '(') {
                f[i] = f[i - 1] + 2;
                if (match - 1 >= 0)
                    f[i] += f[match - 1];
            }
            ret = max(ret, f[i]);
        }
        return ret;
    }
};
