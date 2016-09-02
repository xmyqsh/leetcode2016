class Solution {
public:
    string convertToTitle(int n) {
        stringstream ss;
        while (n) {
            --n;
            ss << (char)(n % 26 + 'A');
            n /= 26;
        }
        string result = ss.str();
        reverse(result.begin(), result.end());
        return result;
    }
};
