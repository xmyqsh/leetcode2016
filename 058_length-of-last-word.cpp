class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1, len = 0;
        while (i >= 0 && s[i] == ' ') --i;
        while (i >= 0 && s[i] != ' ') --i, ++len;
        return len;
    }
};
