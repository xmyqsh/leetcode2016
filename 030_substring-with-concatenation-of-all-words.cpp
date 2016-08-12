class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty() || s.size() < words.size() * words[0].size())
            return result;
        const int wordLen = words[0].size();
        unordered_map<string, int> dict;
        for (int i = 0; i < words.size(); ++i) ++dict[words[i]];
        for (int i = 0; i < wordLen; ++i) {
            int start = i, count = 0;
            unordered_map<string, int> tDict;
            for (int j = i; j + wordLen <= s.size(); j += wordLen) {
                string str = s.substr(j, wordLen);
                if (dict.count(str)) {
                    if (++tDict[str] <= dict[str]) {
                        ++count;
                    } else {
                        while (tDict[str] > dict[str]) {
                            string tmpStr = s.substr(start, wordLen);
                            if (--tDict[tmpStr] < dict[tmpStr]) --count;
                            start += wordLen;
                        }
                    }
                    if (count == words.size()) {
                        result.push_back(start);
                        --tDict[s.substr(start, wordLen)];
                        --count;
                        start += wordLen;
                    }
                } else {
                    tDict.clear();
                    count = 0;
                    start = j + wordLen;
                }
            }
        }
        return result;
    }
};
