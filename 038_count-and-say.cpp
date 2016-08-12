class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        while (--n)
            nextStr(str);
        return str;
    }
    void nextStr(string& str) {
        ostringstream ss;
        for (int b = 0, e; b != str.size();) {
            e = str.find_first_not_of(str[b], b);
            if (e == string::npos) e = str.size();
            ss << e - b << str[b];
            b = e;
        }
        string tmp(ss.str());
        swap(str, tmp);
    }
};
