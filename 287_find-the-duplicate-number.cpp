class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size() - 1; // right = n
        while (left < right) {
            const int mid = left + (right - left) / 2;
            int count = 0;
            for (int i = 0; i < nums.size(); ++i)
                if (nums[i] <= mid) ++count;
            if (count <= mid) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
