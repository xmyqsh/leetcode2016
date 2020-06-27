class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int maxW = 0;
        map<int, int> lastIdx;
        lastIdx[-A[0]] = 0;
        A[0] = 0;
        for (int i = 1; i != A.size(); ++i) {
            int v = 0;
            auto iter = lastIdx.lower_bound(-A[i]);
            if (iter != lastIdx.end()) v = i - iter->second + A[iter->second];
            lastIdx[-A[i]] = i;
            A[i] = v;
            maxW = max(maxW, A[i]);
        }
        return maxW;
    }
};
