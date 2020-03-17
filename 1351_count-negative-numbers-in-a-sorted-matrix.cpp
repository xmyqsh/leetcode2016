// O(N^2)
// TODO: Optimize this
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        for (const auto& r : grid) {
            for (auto n : r) {
                if (n < 0) ++cnt;
            }
        }
        return cnt;
    }
};
