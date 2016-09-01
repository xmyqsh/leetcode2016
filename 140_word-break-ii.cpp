class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<vector<bool> > wordPos(s.size() + 1, vector<bool>(s.size(), false));
        vector<bool> f(s.size() + 1, false);
        f[0] = true;
        int minLen = INT_MAX, maxLen = INT_MIN;
        for (auto word : wordDict) {
            minLen = min(minLen, (int)word.length());
            maxLen = max(maxLen, (int)word.length());
        }
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = minLen, pos = i - minLen; j <= maxLen && pos >= 0; ++j, --pos) {
                if (f[pos] && wordDict.count(s.substr(pos, j))) {
                    f[i] = true;
                    wordPos[i][pos] = true;
                }
            }
        }
        vector<string> result;
        vector<string> path;
        getPath(&result, wordPos, path, s, s.size());
        return result;
    }
    void getPath(vector<string>* result, vector<vector<bool> >& wordPos, vector<string>& path, const string& s, int cur) {
        if (cur == 0) {
            stringstream ss;
            for (int i = path.size() - 1; i > 0; --i) ss << path[i] << " ";
            ss << path[0];
            result->push_back(ss.str());
            return;
        }
        for (int i = cur - 1; i >= 0; --i) {
            if (wordPos[cur][i]) {
                path.push_back(s.substr(i, cur - i));
                getPath(result, wordPos, path, s, i);
                path.pop_back();
            }
        }
    }
};
