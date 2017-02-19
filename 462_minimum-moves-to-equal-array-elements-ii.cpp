// O(nlog(n))
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1, ret = 0;
        while (i < j)
            ret += nums[j--] - nums[i++];
        return ret;
    }
};

// O(n)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ret = 0, median = findMedian(nums);
        // median = *nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        for (auto num : nums)
            ret += abs(num - median);
        return ret;
    }
    int findMedian(vector<int>& nums) {
        return getKth(nums.size() / 2, nums, 0, nums.size() - 1);
    }
    int getKth(int k, vector<int>& nums, int begin, int end) {
        int pivot = nums[end], i, j;
        for (i = begin, j = begin; j < end; ++j) {
            if (nums[j] < pivot)
                swap(nums[i++], nums[j]);
        }
        swap(nums[i], nums[end]);
        if (i == k) return pivot;
        else if (i < k) return getKth(k, nums, i + 1, end);
        else return getKth(k, nums, begin, i - 1);
    }
};
