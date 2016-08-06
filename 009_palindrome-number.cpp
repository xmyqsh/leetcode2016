class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x / 10 == 0) return true;
        stringstream ss;
        ss << x;
        return isPalindrome(ss.str());
    }
    
    bool isPalindrome(const string& str) {
        int b = 0, e = str.size() - 1;
        while (b < e) {
            if (str[b++] != str[e--])
                return false;
        }
        return true;
    }
};
