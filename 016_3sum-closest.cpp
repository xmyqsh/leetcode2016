class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int minGap = INT_MAX, result;
        for (auto a = nums.begin(); a != prev(nums.end(), 1); ++a) {
            if (a != nums.begin() && *a == *prev(a)) continue;
            for (auto b = next(a), c = prev(nums.end()); b < c;) {
                const int sum = *a + *b + *c;
                if (sum == target) return target;
                else if (sum < target) {
                    do { ++b; } while (*b == *prev(b));
                } else {
                    do { --c; } while (*c == *next(c));
                }
                const int gap = abs(sum - target);
                if (gap < minGap) {
                    minGap = gap;
                    result = sum;
                }
            }
        }
        return result;
    }
};
