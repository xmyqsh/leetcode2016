class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        unsigned int unum = num;
        stringstream ss;
        while (unum) {
            int digit = unum % 16;
            ss << (char)(digit < 10 ? (digit + '0') : (digit - 10 + 'a'));
            unum /= 16;
        }
        string result = ss.str();
        reverse(result.begin(), result.end());
        return result;
    }
};
