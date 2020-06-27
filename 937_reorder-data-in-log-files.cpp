class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        unordered_map<int, bool> isLetter;
        unordered_map<int, string> content;
        for (int i = 0; i != logs.size(); ++i) {
            int idx = logs[i].find(' ', 0);
            content[i] = logs[i].substr(idx + 1);
            isLetter[i] = !isdigit(content[i][0]);
        }
        vector<int> logsIdx(logs.size());
        iota(logsIdx.begin(), logsIdx.end(), 0);
        stable_sort(logsIdx.begin(), logsIdx.end(), [&isLetter, &content, &logs](const auto& idx1, const auto& idx2) {
            bool iL1 = isLetter[idx1], iL2 = isLetter[idx2];
            if (!iL1 && !iL2) return false;
            if (!iL1 || !iL2) return iL1;
            return content[idx1] < content[idx2] || (content[idx1] == content[idx2] && logs[idx1] < logs[idx2]);
        });
        vector<string> ret; ret.reserve(logs.size());
        for (auto idx : logsIdx) ret.push_back(logs[idx]);
        return ret;
    }
};
