class Solution {
public:
    bool isValid(string code) {
        stringstream ss;
        int b = 0, e;
        for (; e != code.size(); b = e + 1) {
            e = code.find("<![CDATA[", b);
            if (e == string::npos) {
                e = code.size();
                ss << code.substr(b, e - b);
                break;
            } else {
                ss << code.substr(b, e - b);
                b = e;
                e = code.find("]]>", b);
                if (e == string::npos) return false;
            }
        }
        string newCode = ss.str();
        if (newCode[0] != '<') return false;
        stack<string> sk;
        b = 0;
        bool ket = false;
        for (; b < newCode.size(); b = e + 1) {
            e = newCode.find('<', b);
            if (e == string::npos) return false;
            if (e + 1 == newCode.size()) return false;
            ket = false;
            if (newCode[e + 1] == '/') { ket = true; b = e + 2; }
            else b = e + 1;
            e = newCode.find('>', b);
            if (e == string::npos) return false;
            if (e - b < 1 || e - b > 9) return false;
            string name(e - b, '0');
            for (int i = 0, j = b; j != e; ++i, ++j) {
                if (newCode[j] < 'A' || newCode[j] > 'Z') return false;
                name[i] = newCode[j];
            }
            if (ket) {
                if (sk.empty() || sk.top() != name) return false;
                sk.pop();
                if (sk.empty() && e != newCode.size() - 1) return false;
            } else sk.push(name);
        }
        return sk.empty() && b == newCode.size();
    }
};
