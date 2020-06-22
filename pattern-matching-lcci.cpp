class Solution {
public:
    bool patternMatching(string pattern, string value) {
        if (value.empty()) return pattern.empty() || allsame(pattern);
        int cntA = 0, cntB = 0;
        for (auto c : pattern) c == 'a' ? ++cntA : ++cntB;
        int stepA = cntA == 0 ? 0 : value.size() / cntA;
        int stepB = cntB == 0 ? 0 : value.size() / cntB;
        for (int sA = 0; sA != stepA + 1; ++sA) {
            for (int sB = 0; sB != stepB + 1; ++sB) {
                if (sA == 0 && sB == 0) continue;
                if (sA * cntA + sB * cntB != value.size()) continue;
                int iv = 0;
                unordered_map<char, string> mp;
                bool flag = true;
                for (auto c : pattern) {
                    string sub = c == 'a' ? value.substr(iv, sA) : value.substr(iv, sB);
                    iv += c == 'a' ? sA : sB;
                    if (!mp.count(c)) {
                        mp[c] = sub;
                        if (mp.size() == 2 && mp['a'] == mp['b']) { flag = false; break; }
                    }
                    else if (mp[c] != sub) { flag = false; break; }
                }
                if (flag) return true;
            }
        }
        return false;
    }
    bool allsame(const string& pattern) {
        // assert(!pattern.empty());
        for (int i = 1; i != pattern.size(); ++i) if (pattern[i] != pattern[0]) return false;
        return true;
    }
};
/*
"bbbaa"
"xxxxxxy"
"ab"
"a"
"baabab"
"eimmieimmieeimmiee"
"bbba"
"xxxxxx"
"abba"
"dogcatcatdog"
"aaaa"
"dogcatcatdog"
"bbb"
"xxxxxx"
"a"
""
"ba"
""
""
""
""
"rr"
"abba"
"dogcatcatdog"
"abba"
"dogcatcatfish"
"aaaa"
"dogcatcatdog"
"abba"
"dogdogdogdog"
*/
