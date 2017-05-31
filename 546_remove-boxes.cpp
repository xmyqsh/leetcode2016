class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        unordered_map<int, int> memo;
        return dfs(boxes, memo, 0, boxes.size() - 1, 0);
    }
    int dfs(const vector<int>& boxes, unordered_map<int, int>& memo, int l, int r, int k) {
        if (l > r) return 0;
        int hashVal = hash(l, r, k);
        if (memo.count(hashVal)) return memo[hashVal];
        while (r > l && boxes[r] == boxes[r - 1]) { r--; k++; }
        memo[hashVal] = dfs(boxes, memo, l, r - 1, 0) + (k + 1) * (k + 1);
        for (int i = l; i != r; ++i)
            if (boxes[i] == boxes[r])
                memo[hashVal] = max(memo[hashVal], dfs(boxes, memo, l, i, k + 1) + dfs(boxes, memo, i + 1, r - 1, 0));
        return memo[hashVal];
    }
    int hash(int a, int b, int c) {
        return a * 1000000 + b * 1000 + c;
    }
};
