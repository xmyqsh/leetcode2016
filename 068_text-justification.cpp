class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        for (int i = 0, l, k; i < words.size(); i += k) {
            for (l = k = 0; i + k < words.size() && l + words[i + k].size() <= maxWidth - k; ++k)
                l += words[i + k].size();
            stringstream ss;
            ss << words[i];
            for (int j = 0; j < k - 1; ++j) {
                if (i + k >= words.size()) ss << ' ';
                else ss << string((maxWidth - l) / (k - 1) + (j < ((maxWidth - l) % (k - 1)) ? 1 : 0), ' ');
                ss << words[i + j + 1];
            }
            string tmp = ss.str();
            result.push_back(tmp + string(maxWidth - tmp.size(), ' '));
        }
        return result;
    }
};
