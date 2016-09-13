class Solution {
public:
    bool isAdditiveNumber(string num) {
        for (int i = 1; i <= num.size() / 2; ++i)
            for (int j = i + 1; j - i <= (num.size() - i) / 2; ++j)
                if (check(num.substr(0, i), num.substr(i, j - i), num.substr(j)))
                    return true;
        return false;
    }
    bool check(const string& num1, const string& num2, const string& num) {
        if (num1[0] == '0' && num1.size() > 1) return false;
        if (num2[0] == '0' && num2.size() > 1) return false;
        string sum = add(num1, num2);
        if (sum == num) return true;
        if (sum.size() >= num.size() && sum != num.substr(0, sum.size())) return false;
        return check(num2, sum, num.substr(sum.size()));
    }
    string add(const string& num1, const string& num2) {
        if (num1.size() > num2.size()) return add(num2, num1);
        stringstream ss;
        int carry = 0, j = num2.size() - 1;
        for (int i = num1.size() - 1; i >= 0; --i, --j) {
            int sum = num1[i] - '0' + num2[j] - '0' + carry;
            ss << sum % 10;
            carry = sum / 10;
        }
        for (; j >= 0; --j) {
            int sum = num2[j] - '0' + carry;
            ss << sum % 10;
            carry = sum / 10;
        }
        if (carry) ss << 1;
        string sum = ss.str();
        reverse(sum.begin(), sum.end());
        return sum;
    }
};
