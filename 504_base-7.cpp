class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        int abnum = abs(num);
        stringstream ss;
        while (abnum) {
            ss << (abnum % 7);
            abnum /= 7;
        }
        if (num < 0)
            ss << '-';
        string result = ss.str();
        reverse(result.begin(), result.end());
        return result;
    }
};
