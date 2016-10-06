//  Time Limit Exceeded
class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, bool> reached;
        unordered_set<int> st;
        for (auto stone : stones) st.insert(stone);
        return dfs(st, stones[stones.size() - 1], 0, 1, reached);
    }
    bool dfs(unordered_set<int> st, int end, int pos, int step, unordered_map<int, bool> reached) {
        if (reached.count(pos)) return reached[pos];
        if (pos == end) return true;
        if (pos > end) return false;
        if (step == 0) return false;
        if (st.count(pos)) reached[pos] = dfs(st, end, pos + step, step + 1, reached) ||
                                            dfs(st, end, pos + step, step, reached) ||
                                            dfs(st, end, pos + step, step - 1, reached);
        else reached[pos] = false;
        return reached[pos];
    }
};

// Top-Down Solution
class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, int> mp;
        for (int i = 0; i != stones.size(); ++i) mp[stones[i]] = i;
        for (int i = stones.size() - 2; i >= 0; --i)
            if (canCross(mp, stones[i], stones[stones.size() - 1] - stones[i]))
                return true;
        return false;
    }
    bool canCross(unordered_map<int, int>& mp, int cur, int step) {
        if (step == 0 || cur < 0 || !mp.count(cur)) return false;
        if (cur == 0 && step == 1) return true;
        return canCross(mp, cur - (step - 1), step - 1) ||
                canCross(mp, cur - step, step) ||
                canCross(mp, cur - (step + 1), step + 1);
    }
};
