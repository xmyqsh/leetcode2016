class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> sk;
        int i, j;
        for (i = 0, j = 0; i != pushed.size(); ++i) {
            sk.push(pushed[i]);
            while (!sk.empty() && sk.top() == popped[j]) {
                sk.pop(); ++j;
            }
        }
        while (!sk.empty() && sk.top() == popped[j]) {
            sk.pop(); ++j;
        }
        return sk.empty();
    }
};
