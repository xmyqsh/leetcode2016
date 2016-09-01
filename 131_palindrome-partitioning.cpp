class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > result;
        vector<string> path;
        travel(&result, path, s, 0);
        return result;
    }
    void travel(vector<vector<string> >* result, vector<string>& path, const string& s, int start) {
        if (start == s.size()) {
            result->push_back(path);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                travel(result, path, s, i + 1);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(const string& s, int b, int e) {
        while (b < e) {
            if (s[b] != s[e]) return false;
            else { ++b; --e; }
        }
        return true;
    }
};
