class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long left = -1, right = 0; // left = largest, right = sum;
        for (auto num : nums) {
            left = max(left, (long long)num);
            right += num;
        }
        while (left < right) {
            const long long mid = left + (right - left) / 2;
            if (valid(nums, m, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
    bool valid(const vector<int>& nums, int m, int mid) {
        int sum = 0, cnt = 1;
        for (auto num : nums) {
            sum += num;
            if (sum > mid) {
                sum = num;
                if (++cnt > m) return false;
            }
        }
        return true;
    }
};
