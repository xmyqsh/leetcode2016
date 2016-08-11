class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        if (nums.size() < 3) return result;
        sort(nums.begin(), nums.end());
        for (auto a = nums.begin(); a != prev(nums.end(), 1); ++a) {
            if (a != nums.begin() && *a == *prev(a)) continue;
            for (auto b = next(a), c = prev(nums.end()); b < c;) {
                const int sum = *a + *b + *c;
                if (sum < 0) {
                    do { ++b; } while (*b == *prev(b));
                } else if (sum > 0) {
                    do { --c; } while (*c == *next(c));
                } else {
                    result.push_back({*a, *b, *c});
                    do { ++b; } while (*b == *prev(b));
                    do { --c; } while (*c == *next(c));
                }
            }
        }
        return result;
    }
};
