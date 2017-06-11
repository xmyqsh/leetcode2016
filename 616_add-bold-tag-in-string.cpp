class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        unordered_set<string> st;
        int minLen = INT_MAX;
        int maxLen = 0;
        for (auto& word : dict) {
            minLen = min(minLen, (int)word.size());
            maxLen = max(maxLen, (int)word.size());
            st.insert(word);
        }
        if (s.size() < minLen) return s;
        stringstream ss;
        bool hasB = false;
        int begin = -1;
        for (int i = 0, end = -1; i != s.size(); ++i) {
            string t = i + maxLen < s.size() ? s.substr(i, maxLen) : s.substr(i);
            while (t.size() >= minLen) {
                if (st.count(t)) {
                    end = max(end, i + (int)t.size());
                    break;
                }
                t.pop_back();
            }
            if (hasB) {
                if (end == i) {
                    ss << "</b>";
                    hasB = false;
                }
            } else {
                if (end > i) {
                    ss << "<b>";
                    hasB = true;
                }
            }
            ss << s[i];
        }
        if (hasB) ss << "</b>";
        return ss.str();
    }
};
