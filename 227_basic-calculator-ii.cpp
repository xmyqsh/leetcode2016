class Solution {
public:
    int calculate(string s) {
        istringstream in('+' + s + '+');
        int total = 0, term = 0, sign = 1, n;
        char op;
        while (in >> op) {
            if (op == '+' || op == '-') {
                total += sign * term;
                in >> term;
                term = op == '+' ? term : -term;
            } else {
                in >> n;
                if (op == '*') term *= n;
                else term /= n;
            }
        }
        return total;
    }
};
