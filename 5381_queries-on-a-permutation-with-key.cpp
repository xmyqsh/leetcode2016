class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> result;
        vector<int> P(m);
        iota(P.begin(), P.end(), 1);
        for (auto q : queries) {
            result.push_back(0);
            while (P[result.back()] != q) result.back() += 1;
            for (int i = result.back() - 1; i != -1; --i) swap(P[i], P[i + 1]);
        }
        return result;
    }
};
