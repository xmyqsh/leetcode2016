class Solution {
public:
    char findTheDifference(string s, string t) {
        int charSet[256] = {0};
        for (int i = 0; i < s.size(); ++i)
            ++charSet[t[i]], --charSet[s[i]];
        ++charSet[t[s.size()]];
        int i = 'a';
        for (; charSet[i] == 0; ++i);
        return (char)(i);
    }
};
