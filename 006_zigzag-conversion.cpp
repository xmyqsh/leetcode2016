class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows < 2) return s;
        ostringstream ss;
        for (int i = 1; i <= numRows; ++i) {
            bool flag = true;
            for (int j = i - 1; j < s.size();) {
                ss << s[j];
                if (i == 1 || i == numRows) {
                    j += 2 * (numRows - 1);
                } else {
                    j += 2 * (flag ? numRows - i : i - 1);
                    flag = !flag;
                }
            }
        }
        return ss.str();
    }
};
