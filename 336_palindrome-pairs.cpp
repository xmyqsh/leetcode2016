class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int> > result;
        unordered_map<string, int> mp;
        for (int i = 0; i != words.size(); ++i) {
            string key = words[i];
            reverse(key.begin(), key.end());
            mp[key] = i;
        }
        for (int i = 0; i != words.size(); ++i) {
            for (int j = 0; j != words[i].size(); ++j) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j);
                if (mp.count(left) && isPalindrome(right) && mp[left] != i) result.push_back({i, mp[left]});
                if (mp.count(right) && isPalindrome(left) && mp[right] != i) result.push_back({mp[right], i});
            }
        }
        if (mp.count(""))
            for (int i = 0; i != words.size(); ++i)
                if (isPalindrome(words[i]) && mp[""] != i) result.push_back({mp[""], i});
        return result;
    }
    bool isPalindrome(const string& s) {
        int b = 0, e = s.size() - 1;
        while (b < e && s[b] == s[e]) { ++b; --e; }
        return b >= e;
    }
};
