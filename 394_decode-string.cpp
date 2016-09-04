class Solution {
public:
    string decodeString(string s) {
        if (s.empty()) return s;
        stringstream ss;
        int l = 0, r = 0, cnt;
        while (l < s.size()) {
            while (r < s.size() && !isdigit(s[r])) ss << s[r++];
            if (r == s.size()) break;
            l = r;
            while (isdigit(s[r])) ++r;
            cnt = stoi(s.substr(l, r - l));
            l = r + 1;
            int count = 1;
            while (count != 0) {
                ++r;
                if (s[r] == '[') ++count;
                else if (s[r] == ']') --count;
            }
            string inner = decodeString(s.substr(l, r - l));
            while (cnt--) ss << inner;
            l = r + 1;
            r = l;
        }
        return ss.str();
    }
};
