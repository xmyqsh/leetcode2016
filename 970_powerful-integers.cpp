class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        if (bound < 2) return {};
        if (x == 1 && y == 1) return {2};
        if (x == 1) return powerfulIntegers(y, bound);
        if (y == 1) return powerfulIntegers(x, bound);
        unordered_set<int> st;
        for (int px = 1; px < bound; px *= x) {
            for (int py = 1; ; py *= y) {
                if (py + px <= bound) st.insert(py + px);
                else break;
            }
        }
        vector<int> result; result.reserve(st.size());
        for (auto n : st) result.push_back(n);
        return result;
    }
    vector<int> powerfulIntegers(int x, int bound) {
        vector<int> result;
        for (int px = 1; ; px *= x) {
            if (1 + px <= bound) result.push_back(1 + px);
            else break;
        }
        return result;
    }
};
