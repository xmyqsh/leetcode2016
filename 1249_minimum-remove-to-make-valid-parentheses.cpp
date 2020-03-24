class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stringstream ss;
        int cnt = 0;
        for (auto c : s) {
            if (c == '(') {
                ++cnt;
                ss << c;
            } else if (c == ')') {
                if (cnt != 0) {
                    --cnt;
                    ss << c;
                }
            } else ss << c;
        }
        s = ss.str();
        reverse(s.begin(), s.end());
        stringstream ss1;
        cnt = 0;
        for (auto c : s) {
            if (c == ')') {
                ++cnt;
                ss1 << c;
            } else if (c == '(') {
                if (cnt != 0) {
                    --cnt;
                    ss1 << c;
                }
            } else ss1 << c;
        }
        s = ss1.str();
        reverse(s.begin(), s.end());
        return s;
    }
};
