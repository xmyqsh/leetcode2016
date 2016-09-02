class Solution {
public:
    void reverseWords(string &s) {
        int b = s.find_first_not_of(' '), e;
        s.erase(0, b);
        reverse(s, 0, s.size());
        b = s.find_first_not_of(' ');
        s.erase(0, b);
        for (b = 0; b < s.size();) {
            if ((e = s.find_first_of(' ', b)) == string::npos)
                e = s.size();
            reverse(s, b, e);
            if ((b = s.find_first_not_of(' ', e)) == string::npos)
                b = s.size();
            s.erase(e, b - e - 1);
            b = e + 1;
        }
    }
    void reverse(string& s, int b, int e) {
        --e;
        while (b < e) swap(s[b++], s[e--]);
    }
};
