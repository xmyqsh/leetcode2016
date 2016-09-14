class Solution {
public:
    string reverseString(string s) {
        int b = 0, e = s.size() - 1;
        while (b < e) swap(s[b++], s[e--]);
        return s;
    }
};
