// Enumerate catalan, catch state is meaningless, c(2n,n)/(n+1) = c(2n,n)-c(2n,n-1), O((2n)!), TLE
class Solution {
public:
    int countEval(string s, int result) {
        stack<pair<bool, char>> sbp;
        return countEval(s, sbp, result == 1, 0);
    }
    int countEval(string& s, stack<pair<bool, char>>& sbp, const bool target, int idx) {
        if (idx == s.size() - 1 && sbp.empty()) {
            return target == (s[idx] == '1');
        }
        int cnt = 0;
        if (!sbp.empty()) {
            char tmp = s[idx];
            auto [tsb, tsp] = sbp.top();
            s[idx] = eval(tsb, tsp, s[idx] == '1') ? '1' : '0';
            sbp.pop();
            cnt += countEval(s, sbp, target, idx);
            sbp.push({tsb, tsp});
            s[idx] = tmp;
        }
        if (idx != s.size() - 1) {
            sbp.push({s[idx] == '1', s[idx + 1]});
            cnt += countEval(s, sbp, target, idx + 2);
            sbp.pop();
        }
        return cnt;
    }
    bool eval(bool left, char op, bool right) {
        switch (op) {
            case '&': return left & right;
            case '|': return left | right;
            case '^': return left ^ right;
            default: assert(0);
        }
        return false;
    }
};

// Divide and conquer, catch state, O(带cache的主定理不会算), AC
class Solution {
public:
    int countEval(string s, int result) {
        unordered_map<int, unordered_map<int, vector<int>>> mp;
        return countEval(s, 0, s.size() - 1, mp)[result];
    }
    const vector<int>& countEval(const string& s, int b, int e,
        unordered_map<int, unordered_map<int, vector<int>>>& mp) {
        if (mp[b].count(e)) return mp[b][e];
        vector<int> ret(2, 0);
        if (b == e) {
            ret[s[b] == '1'] = 1;
            mp[b][e] = move(ret);
            return mp[b][e];
        }
        for (int i = b + 1; i <= e - 1; i += 2) {
            char op = s[i];
            auto& left = countEval(s, b, i - 1, mp);
            auto& right = countEval(s, i + 1, e, mp);
            for (int i = 0; i != 2; ++i) {
                for (int j = 0; j != 2; ++j) {
                    ret[eval(i == 1, op, j == 1)] += left[i] * right[j];
                }
            }
        }
        mp[b][e] = move(ret);
        return mp[b][e];
    }
    bool eval(bool left, char op, bool right) {
        switch (op) {
            case '&': return left & right;
            case '|': return left | right;
            case '^': return left ^ right;
            default: assert(0);
        }
        return false;
    }
};
