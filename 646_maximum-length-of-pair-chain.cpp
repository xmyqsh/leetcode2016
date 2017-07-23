class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.empty()) return 0;
        sort(pairs.begin(), pairs.end(), [](const vector<int>& p1, const vector<int>& p2) {
            return p1[0] <= p2[0];
        });
        int ret = 1, curEnd = pairs[0][1];
        for (int i = 1; i != pairs.size(); ++i) {
            if (curEnd < pairs[i][0]) {
                ++ret;
                curEnd = pairs[i][1];
            } else {
                curEnd = min(curEnd, pairs[i][1]);
            }
        }
        return ret;
    }
};
