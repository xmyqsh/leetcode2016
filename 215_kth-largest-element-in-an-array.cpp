class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k/* + 1*/;
        int b = 0, e = nums.size() - 1;
        int idx = partition(nums, b, e);
        while (idx/* + 1*/ != k) {
            if (idx < k) b = idx + 1;
            else e = idx - 1;
            idx = partition(nums, b, e);
        }
        return nums[idx];
    }
    int partition(vector<int>& nums, int b, int e) {
        int idx = b, pivot = nums[e];
        for (int i = b; i < e; ++i)
            if (nums[i] < pivot)
                swap(nums[idx++], nums[i]);
        swap(nums[idx], nums[e]);
        return idx;
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        int b = 0, e = nums.size() - 1, idx;
        while (b <= e) {
            idx = b;
            for (int i = b, pivot = nums[e]; i < e; ++i)
                if (nums[i] < pivot)
                    swap(nums[idx++], nums[i]);
            swap(nums[idx], nums[e]);
            if (idx < k) b = idx + 1;
            else if (idx > k) e = idx - 1;
            else break;
        }
        return nums[idx];
    }
};
