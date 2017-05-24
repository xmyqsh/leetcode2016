class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() < 2) return;
        int n = nums.size();
        auto midPtr = nums.begin() + n / 2;
        nth_element(nums.begin(), midPtr, nums.end());
        int mid = *midPtr;
        // virtual index
        #define A(x) nums[(1 + 2 * (x)) % (n | 1)]
        int i = 0, j = 0, k = n - 1;
        // three-way-partition
        while (j <= k) {
            if (A(j) > mid) swap(A(i++), A(j++));
            else if (A(j) < mid) swap(A(k--), A(j));
            else ++j;
        }
    }
};
