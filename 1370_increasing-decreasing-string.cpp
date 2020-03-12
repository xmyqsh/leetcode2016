class Solution {
public:
    string sortString(string s) {
        map<char, int> mp;
        for (auto c : s) ++mp[c];
        stringstream ss;
        while (!mp.empty()) {
            for (auto iter = mp.begin(); iter != mp.end(); ) {
                ss << iter->first;
                if (--iter->second == 0) {
                    iter = mp.erase(iter);
                } else ++iter;
            }
            stringstream subss;
            for (auto iter = mp.begin(); iter != mp.end(); ) {
                subss << iter->first;
                if (--iter->second == 0) {
                    iter = mp.erase(iter);
                } else ++iter;
            }
            string substr = subss.str();
            reverse(substr.begin(), substr.end());
            ss << substr;
        }
        return ss.str();
    }
};
