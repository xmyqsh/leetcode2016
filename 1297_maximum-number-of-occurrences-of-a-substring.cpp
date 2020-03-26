class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int ret = 0;
        for (int sz = minSize; sz != maxSize + 1; ++sz) {
            unordered_map<char, int> mp;
            unordered_map<string, int> str2num;
            int b = 0, e = 0;
            while (e != sz) ++mp[s[e++]];
            if (mp.size() <= maxLetters) ++str2num[s.substr(b, e - b)];
            for (; e != s.size(); ) {
                if (--mp[s[b]] == 0) mp.erase(s[b]);
                b++;
                ++mp[s[e++]];
                if (mp.size() <= maxLetters) ++str2num[s.substr(b, e - b)];
            }
            for (const auto& item : str2num) {
                ret = max(ret, item.second);
            }
        }
        return ret;
    }
};
