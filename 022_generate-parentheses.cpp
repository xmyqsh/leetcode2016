class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return vector<string>(1, "");
        if (n == 1) return vector<string>(1, "()");
        vector<string> result;
        for (int i = 0; i < n; ++i) {
            for (auto outer : generateParenthesis(i)) {
                for (auto inner : generateParenthesis(n - i - 1))
                    result.push_back(outer + '(' + inner + ')');
            }
        }
        return result;
    }
};
