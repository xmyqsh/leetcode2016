class Solution {
public:
    int calculate(string s) {
        stack<int> nums, ops;
        int ret = 0, num = 0, sign = 1;
        for (auto c : s) {
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            } else {
                ret += sign * num;
                num = 0;
                if (c == '+') sign = 1;
                else if (c == '-') sign = -1;
                else if (c == '(') {
                    nums.push(ret);
                    ops.push(sign);
                    sign = 1;
                    ret = 0;
                } else if (c == ')') {
                    ret = ops.top() * ret + nums.top();
                    ops.pop(); nums.pop();
                }
            }
        }
        return ret + sign * num;
    }
};
