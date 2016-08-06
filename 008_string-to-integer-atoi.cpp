class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        int flag = 1, i = 0;
        while (i < str.size() && str[i] == ' ') ++i;
        if (str[i] == '+') ++i;
        else if (str[i] == '-') {
            ++i;
            flag = -1;
        }
        int result = 0;
        for (; i < str.size(); ++i) {
            if (!isdigit(str[i])) break;
            int num = str[i] - '0';
            if ((INT_MAX - num) / 10 < result)
                return flag == 1 ? INT_MAX : INT_MIN;
            result = result * 10 + num;
        }
        return flag * result;
    }
};
