class Solution {
public:
    string fractionAddition(string expression) {
        if (expression.empty()) return "";
        int sign = expression[0] == '-' ? -1 : 1;
        int idx = 1;
        vector<int> numerator, denominator;
        for (; idx != expression.size(); ++idx) {
            if (expression[idx] == '/') {
                numerator.push_back(sign * (expression[idx - 1] == '0' ? 10 : expression[idx - 1] - '0'));
                denominator.push_back(expression[idx + 2] == '0' ? 10 : expression[idx + 1] - '0');
            } else if (expression[idx] == '+') {
                sign = 1;
            } else if (expression[idx] == '-') {
                sign = -1;
            }
        }
        int mul = 1;
        for (int i = 2; i != 11; ++i)
            mul *= i;
        int resultNumerator = 0;
        for (int i = 0; i != denominator.size(); ++i)
            resultNumerator += numerator[i] * mul / denominator[i];
        if (resultNumerator < 0) {
            sign = -1;
            resultNumerator = -resultNumerator;
        } else sign = 1;
        int gcd = GCD(resultNumerator, mul);
        stringstream ss;
        ss << (sign == -1 ? "-" : "") << (resultNumerator / gcd) << '/' << (mul / gcd);
        return ss.str();
    }
    int GCD(int a, int b) {
	    if(b) while((a %= b) && (b %= a));
	    return a + b;
    }
};
