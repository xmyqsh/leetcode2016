class Solution {
public:
    string solveEquation(string equation) {
        int pos = equation.find('=', 0);
        if (pos == string::npos) return "No solution";
        int b = 0, e, sign = 1;
        int x = 0, num = 0;
        if (equation[b] == '+') {
            ++b;
        } else if (equation[b] == '-') {
            ++b;
            sign = -1;
        }
        for (e = b + 1; ; e = b + 1) {
            while (equation[e] != '=' && equation[e] != '+' && equation[e] != '-') ++e;    
            if (equation[e - 1] == 'x') {
                if (e == b + 1) x += sign;
                else x += sign * stoi(equation.substr(b, e - 1 - b));
            } else {
                num -= sign * stoi(equation.substr(b, e - b));
            }
            b = e + 1;
            if (equation[e] == '+') sign = 1;
            else if (equation[e] == '-') sign = -1;
            else break;
        }
        
        sign = 1;
        if (equation[b] == '+') {
            ++b;
        } else if (equation[b] == '-') {
            ++b;
            sign = -1;
        }
        for (e = b + 1; ; e = b + 1) {
            while (e != equation.size() && equation[e] != '+' && equation[e] != '-') ++e;    
            if (equation[e - 1] == 'x') {
                if (e == b + 1) x -= sign;
                else x -= sign * stoi(equation.substr(b, e - 1 - b));
            } else {
                num += sign * stoi(equation.substr(b, e - b));
            }
            b = e + 1;
            if (equation[e] == '+') sign = 1;
            else if (equation[e] == '-') sign = -1;
            else break;
        }
        
        if (x == 0) {
            if (num == 0) return "Infinite solutions";
            return "No solution";
        }
        return "x=" + to_string(num / x);
    }
};
