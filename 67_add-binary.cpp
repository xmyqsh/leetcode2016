class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() > b.size()) return addBinary(b, a);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        stringstream ss;
        int carry = 0;
        for (int i = 0; i < a.size(); ++i) {
            const int sum = a[i] + b[i] + carry - '0' - '0';
            ss << sum % 2;
            carry = sum / 2;
        }
        for (int i = a.size(); i < b.size(); ++i) {
            const int sum = b[i] + carry - '0';
            ss << sum % 2;
            carry = sum / 2;
        }
        if (carry) ss << 1;
        string result = ss.str();
        reverse(result.begin(), result.end());
        return result;
    }
};
