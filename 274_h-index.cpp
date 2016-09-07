class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int i;
        for (i = 0; i < citations.size(); ++i)
            if (citations[i] >= citations.size() - i)
                break;
        return citations.size() - i;
    }
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> count(citations.size() + 1, 0);
        for (auto c : citations)
            if (c >= citations.size()) ++count[citations.size()];
            else ++count[c];
        int hIndex = 0;
        for (int i = count.size() - 1; i >= 0; --i) {
            hIndex += count[i];
            if (hIndex >= i) return i;
        }
        return 0;
    }
};
