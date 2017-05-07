class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int subLen = 1;
        while (subLen != s.size() && s.substr(0, s.size() - subLen) != s.substr(subLen))
            ++subLen;
        if (subLen == s.size())
            return false;
        return s.substr(0, subLen) == s.substr(s.size() - subLen);
    }
};
