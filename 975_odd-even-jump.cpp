class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        map<long long, int> odd, even;
        for (int i = 0; i != A.size(); ++i) {
            odd[A[i] * (long long)100000 + i] = i;
            even[-A[i] * (long long)100000 + i] = i;
        }
        // number of arrive at dp[idx]
        vector<int> oddJump(A.size(), 1), evenJump(A.size(), 0);
        for (int i = 0; i != A.size() - 1; ++i) {
            odd.erase(A[i] * (long long)100000 + i);
            even.erase(-A[i] * (long long)100000 + i);
            // odd --> even
            auto iter = odd.lower_bound(A[i] * (long long)100000 + i);
            if (iter != odd.end()) {
                evenJump[iter->second] += oddJump[i];
            }
            // even --> odd
            if (evenJump[i]) {
                auto iter = even.lower_bound(-A[i] * (long long)100000 + i);
                if (iter != even.end()) {
                    oddJump[iter->second] += evenJump[i];
                }
            }
        }
        return oddJump[A.size() - 1] + evenJump[A.size() - 1];
    }
};
