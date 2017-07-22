class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n, 0);
        stack<int> sk;
        int l, t, id;
        char st[8];
        for (auto log : logs) {
            sscanf(log.c_str(), "%d:%[^:]:%d", &id, st, &t);
            if (st[0] == 'e') {
                result[sk.top()] += ++t - l;
                sk.pop();
            } else {
                if (!sk.empty()) result[sk.top()] += t - l;
                sk.push(id);
            }
            l = t;
        }
        return result;
    }
};
