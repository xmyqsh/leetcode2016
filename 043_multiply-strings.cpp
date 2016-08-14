class Solution {
public:
    string multiply(string num1, string num2) {
        string result(num1.size() + num2.size(), '0');
        for (int i = num1.size() - 1; i >= 0; --i) {
            int carry = 0;
            for (int j = num2.size() - 1; j >= 0; --j) {
                const int mul = (result[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                result[i + j + 1] = (mul % 10) + '0';
                carry = mul / 10;
            }
            result[i] += carry;
        }
        int pos = result.find_first_not_of('0');
        result.erase(0, pos);
        return result.size() == 0 ? "0" : result;
    }
};
