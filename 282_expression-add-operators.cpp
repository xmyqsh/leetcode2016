class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        for (int i = 1; i <= num.size(); ++i) {
            string cur = num.substr(0, i);
            if (cur.size() > 1 && cur[0] == '0') continue;
            long cv = stol(cur);
            dfs(&result, num, i, target, cur, cv, cv, '*');
        }
        return result;
    }
    void dfs(vector<string>* result, const string& num, int pos, const int target, string cur, const long cv, const long pv, const char op) {
        if (pos == num.size() && cv == target) {
            result->push_back(cur);
            return;
        }
        for (int i = pos + 1; i <= num.size(); ++i) {
            string sub = num.substr(pos, i - pos);
            if (sub.size() > 1 && sub[0] == '0') continue;
            long now = stol(sub);
            dfs(result, num, i, target, cur + '+' + sub, cv + now, now, '+');
            dfs(result, num, i, target, cur + '-' + sub, cv - now, now, '-');
            dfs(result, num, i, target, cur + '*' + sub, op == '+' ? cv - pv + pv * now : (op == '-' ? cv + pv - pv * now :
                pv * now), pv * now, op);
        }
    }
};
