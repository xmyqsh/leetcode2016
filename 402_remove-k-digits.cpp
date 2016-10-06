// O(k * n)
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == k) return "0";
        for (int i = 0, j; i != k; ++i) {
            for (j = 1; j != num.size() && num[j - 1] <= num[j]; ++j);
            if (j != num.size()) num.erase(j - 1, 1);
            else num.erase(num.size() - 1);
        }
        int i = 0;
        while (num[i] == '0') ++i;
        num.erase(0, i);
        return num.empty() ? "0" : num;
    }
};

// O(n)
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> sk; int i;
        for (i = 0; k && i != num.size(); ++i) {
            while (k && !sk.empty() && sk.top() > num[i]) {
                sk.pop();
                --k;
            }
            sk.push(num[i]);
        }
        stringstream ss; string result;
        while (!sk.empty()) {
            ss << sk.top();
            sk.pop();
        }
        result = ss.str();
        reverse(result.begin(), result.end());
        result.append(num.substr(i, (int)num.size() - i));
        result.erase((int)result.size() - k);
        for (i = 0; i != result.size() && result[i] == '0'; ++i);
        result.erase(0, i);
        return result.empty() ? "0" : result;
    }
};
