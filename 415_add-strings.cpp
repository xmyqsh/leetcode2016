class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.size() > num2.size()) return addStrings(num2, num1);
        if (num1.empty()) return num2;
        stringstream ss;
        int carry = 0, gap = num2.size() - num1.size();
        for (int i = num2.size() - 1; i >= gap; --i) {
            int sum = num2[i] - '0' + num1[i - gap] - '0' + carry;
            ss << (sum % 10);
            carry = sum / 10;
        }
        for (int i = gap - 1; i >= 0; --i) {
            int sum = num2[i] - '0' + carry;
            ss << (sum % 10);
            carry = sum / 10;
        }
        if (carry) ss << 1;
        string result = ss.str();
        reverse(result.begin(), result.end());
        return result;
    }
};
