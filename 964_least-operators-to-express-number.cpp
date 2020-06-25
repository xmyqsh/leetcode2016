class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        unordered_map<int, unordered_map<int, int>> dp;
        return leastOpsExpressTarget(0, target, dp, x, -1) - 1;
    }
    int leastOpsExpressTarget(int e, int target, unordered_map<int, unordered_map<int, int>>& dp, int x, int last_target) {
        if (target == 0) return 0;
        if (target == 1) return cost(e);
        // 2 /(%) 2 termination
        if (target == last_target) return target + 1;
        if (dp[e].count(target)) return dp[e][target];
        int d = target / x;
        int r = target % x;
        dp[e][target] = min(
                r * cost(e) + leastOpsExpressTarget(e + 1, d, dp, x, target),
          (x - r) * cost(e) + leastOpsExpressTarget(e + 1, d + 1, dp, x, target)
        );
        return dp[e][target];
    }
    int cost(int e) {
        return e == 0 ? 2 : e;
    }
};
/*
+: 1
-: 1
*: 1
+1: 2
-1: 2
*/
