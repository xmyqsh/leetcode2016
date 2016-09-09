class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        vector<int> dp(nums.size(), 1);
        int ret = 1;
        for (int i = 1; i != nums.size(); ++i) {
            for (int j = i - 1; j >= 0; --j)
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        vector<int> tail(nums.size());
        tail[0] = nums[0];
        int e = 0;
        for (int i = 1; i != nums.size(); ++i) {
            if (nums[i] <= tail[0]) tail[0] = nums[i];
            else if (nums[i] > tail[e]) tail[++e] = nums[i];
            else tail[binarySearch(tail, 0, e, nums[i])] = nums[i];
        }
        return e + 1;
    }
    int binarySearch(vector<int>& tail, int b, int e, int num) {
        while (b < e) {
            const int mid = b + (e - b) / 2;
            if (tail[mid] < num) b = mid + 1;
            else if (tail[mid] > num) e = mid;
            else return mid;
        }
        return e;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        vector<int> tail(nums.size());
        tail[0] = nums[0];
        int e = 0;
        for (int i = 1; i != nums.size(); ++i) {
            if (nums[i] <= tail[0]) tail[0] = nums[i];
            else if (nums[i] > tail[e]) tail[++e] = nums[i];
            else *lower_bound(tail.begin(), tail.begin() + e + 1, nums[i]) = nums[i];
        }
        return e + 1;
    }
};
