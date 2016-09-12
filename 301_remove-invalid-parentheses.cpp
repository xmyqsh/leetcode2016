class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        string path;
        travel(result, path, s, 0, 0);
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        if (result.empty()) result.push_back("");
        return result;
    }
    void travel(vector<string>& result, string path, const string& s, int count, int pos) {
        if (count < 0) return;
        if (pos == s.size()) {
            if (count == 0 && !path.empty()) {
                if (result.empty() || result.back().size() == path.size())
                    result.push_back(path);
            }
            return;
        }
        if (s[pos] != '(' && s[pos] != ')')
            travel(result, path + s[pos], s, count, pos + 1);
        else {
            travel(result, path + s[pos], s, count + (s[pos] == '(' ? 1 : -1), pos + 1);
            travel(result, path, s, count, pos + 1);
        }
    }
};
