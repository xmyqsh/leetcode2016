class Solution {
public:
    int countSegments(string s) {
        if (s.empty()) return 0;
        int result = 0;
        bool isSpace = true;
        for (auto c : s) {
            if (c == ' ') isSpace = true;
            else if (isSpace) {
                isSpace = false;
                ++result;
            }
        }
        return result;
    }
};
