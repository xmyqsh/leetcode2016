class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        unordered_set<int> invalid;
        vector<int> result;
        int cnt = 0;
        while (cnt != target.size()) {
            assert(cnt < target.size());
            int tmp = move(stamp, target, result, invalid);
            if (tmp == -1) return {};
            cnt += tmp;
        }
        reverse(result.begin(), result.end());
        return result;
    }
    int move(const string& stamp, string& target, vector<int>& result, unordered_set<int>& invalid) {
        int i, j, cnt;
        for (i = 0; i + stamp.size() != target.size() + 1; ++i) {
            if (invalid.count(i)) continue;
            for (cnt = 0, j = 0; j != stamp.size(); ++j) {
                if (target[i + j] == '?') ++cnt;
                else if (target[i + j] != stamp[j]) break;
            }
            if (j == stamp.size() && cnt != stamp.size()) break;
            if (j == stamp.size()) {
                if (cnt == stamp.size()) invalid.insert(i);
                else break;
            }
        }
        if (i + stamp.size() == target.size() + 1) return -1;
        result.push_back(i);
        for (cnt = 0, j = 0; j != stamp.size(); ++j) {
            if (target[i + j] != '?') {
                target[i + j] = '?'; ++cnt;
            }
        }
        return cnt;
    }
};
