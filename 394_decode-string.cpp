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

// stack beats 100%
class Solution {
public:
    string decodeString(string s) {
        stringstream ss;
        stack<pair<int, string>> sk;
        int b = 0, e = 0;
        while (e != s.size()) {
            while (e != s.size() && isalpha(s[e])) {
                if (sk.empty()) ss << s[e++];
                else sk.top().second.push_back(s[e++]);
            }
            if (e == s.size()) break;
            if (s[e] == ']') {
                assert(!sk.empty());
                auto p = sk.top(); sk.pop();
                if (sk.empty()) while (p.first--) ss << p.second;
                else while (p.first--) sk.top().second += p.second;
            } else if (isdigit(s[e])){
                b = e;
                while (s[e] != '[') ++e;
                sk.push({stoi(s.substr(b, e - b)), ""});
            }
            b = e + 1;
            e = b;
        }
        return ss.str();
    }
};
