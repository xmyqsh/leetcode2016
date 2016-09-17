class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> cache(target + 1, -1); cache[0] = 1;
        return combinationSum4(nums, cache, target);
    }
    int combinationSum4(const vector<int>& nums, vector<int>& cache, int remain) {
        if (remain == 0) return 1;
        if (remain < 0) return 0;
        if (cache[remain] != -1) return cache[remain];
        cache[remain] = 0;
        for (auto num : nums) cache[remain] += combinationSum4(nums, cache, remain - num);
        return cache[remain];
    }
};
