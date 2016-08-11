class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return true;
        string left = "({[";
        string right = ")}]";
        stack<char> sk;
        for (int i = 0; i < s.size(); ++i) {
            if (left.find(s[i]) != string::npos)
                sk.push(s[i]);
            else if (!sk.empty() && sk.top() == left[right.find(s[i])])
                sk.pop();
            else
                return false;
        }
        return sk.empty();
    }
};
