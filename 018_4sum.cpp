class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result;
        if (nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                if (j != i + 1 && nums[j] == nums[j - 1]) continue;
                const int newTarget = target - nums[i] - nums[j];
                for (int b = j + 1, e = nums.size() - 1; b < e;) {
                    const int sum = nums[b] + nums[e];
                    if (sum < newTarget) {
                        do { ++b; } while (nums[b] == nums[b - 1]);
                    } else if (sum > newTarget) {
                        do { --e; } while (nums[e] == nums[e + 1]);
                    } else {
                        result.push_back({nums[i], nums[j], nums[b], nums[e]});
                        do { ++b; } while (nums[b] == nums[b - 1]);
                        do { --e; } while (nums[e] == nums[e + 1]);
                    }
                }
            }
        }
        return result;
    }
};

// Time Limit Exceeded
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result;
        if (nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        for (auto a = nums.begin(); a != prev(nums.end(), 2); ++a) {
            if (a != nums.begin() && *a == *prev(a)) continue;
            for (auto b = next(a); b != prev(nums.end(), 1); ++b) {
                if (b != next(a) && *b == *prev(b)) continue;
                for (auto c = next(b), d = prev(nums.end()); c < d;) {
                    const int sum = *a + *b + *c + *d;
                    if (sum < target) {
                        do { ++c; } while (*c == *prev(c));
                    } else if (sum > target) {
                        do { --d; } while (*d == *next(d));
                    } else {
                        result.push_back({*a, *b, *c, *d});
                        do { ++c; } while (*c == *prev(c));
                        do { --d; } while (*d == *next(d));
                    }
                }
            }
        }
        return result;
    }
};
