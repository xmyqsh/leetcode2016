class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> mp(26, string(""));
        unordered_map<string, int> mpSC;
        int i = 0, b = 0;
        for (int e; b < str.size() && i != pattern.size(); ++i) {
            int c = pattern[i] - 'a';
            e = str.find_first_of(' ', b);
            if (e == string::npos) e = str.size();
            string sub = str.substr(b, e - b);
            if (mp[c].empty()) {
                if (mpSC.count(sub)) return false;
                mp[c] = sub;
                mpSC[sub] = c;
            } else if (mp[c] != sub) return false;
            else if (!mpSC.count(sub) || mpSC[sub] != c) return false;
            b = e + 1;
        }
        return i == pattern.size() && b - 1 == str.size();
    }
};
