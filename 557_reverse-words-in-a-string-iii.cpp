class Solution {
public:
    string reverseWords(string s) {
        int b = 0, e;
        do {
            e = s.find_first_of(' ', b);
            if (e == string::npos)
                e = s.size();
            reverseWord(s, b, e - 1);
            if (e == s.size())
                break;
            b = s.find_first_not_of(' ', e);
        } while (b != string::npos);
        return s;
    }
    void reverseWord(string& s, int b, int e) {
        while (b < e)
            swap(s[b++], s[e--]);
    }
};
