class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sk;
        for (int i = 0; i < tokens.size(); ++i) {
            if (isOp(tokens[i])) {
                int num2 = sk.top(); sk.pop();
                int num1 = sk.top(); sk.pop();
                switch (tokens[i][0]) {
                    case '+':
                        sk.push(num1 + num2);
                        break;
                    case '-':
                        sk.push(num1 - num2);
                        break;
                    case '*':
                        sk.push(num1 * num2);
                        break;
                    case '/':
                        sk.push(num1 / num2);
                        break;
                }
            } else {
                sk.push(stoi(tokens[i]));
            }
        }
        return sk.top();
    }
    bool isOp(const string& s) {
        return s.size() == 1 && string("+-*/").find(s[0]) != string::npos;
    }
};
