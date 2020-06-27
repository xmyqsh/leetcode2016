class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        if (tokens.empty()) return 0;
        sort(tokens.begin(), tokens.end());
        if (P < tokens[0]) return 0;
        deque<int> dq;
        for (auto t : tokens) dq.push_back(t);
        int ret = 0, point = 0;
        while (!dq.empty()) {
            if (point == 0 && dq.front() > P) break;
            while (!dq.empty() && dq.front() <= P) {
                ++point;
                P -= dq.front();
                dq.pop_front();
            }
            ret = max(ret, point);
            while (!dq.empty() && dq.front() > P && point > 0) {
                --point;
                P += dq.back();
                dq.pop_back();
            }
        }
        return ret;
    }
};
