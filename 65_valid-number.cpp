class Solution {
public:
    bool isNumber(string s) {
        int i = 0, len = s.length();
        for (; i < len && s[i] == ' '; ++i);
        if (i < len && s[i] == '+' || s[i] == '-') ++i;
        int numCnt = 0, ptCnt = 0;
        for (; i < len && ptCnt <= 1 && isdigit(s[i]) || s[i] == '.'; ++i)
            s[i] == '.' ? ++ptCnt : ++numCnt;
        if (ptCnt > 1 || numCnt == 0) return false;
        if (i < len && s[i] == 'e') {
            ++i;
            if (i < len && s[i] == '+' || s[i] == '-') ++i;
            for (numCnt = 0; i < len && isdigit(s[i]); ++i, ++numCnt);
            if (numCnt == 0) return false;
        }
        for (; i < len && s[i] == ' '; ++i);
        return i == len;
    }
};
