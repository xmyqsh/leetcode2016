class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string common = strs[0];
        int len = common.size();
        for (int i = 1; i < strs.size(); ++i) {
            int j = 0;
            for (; j < len && j < strs[i].size() && common[j] == strs[i][j]; ++j);
            len = j;
        }
        return common.substr(0, len);
    }
};
