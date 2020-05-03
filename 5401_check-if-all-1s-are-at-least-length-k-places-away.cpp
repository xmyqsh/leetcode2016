class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int b = 0, e;
        while (b != nums.size() && nums[b] == 0) ++b;
        for (e = b + 1; e < nums.size(); ++e) {
            if (nums[e] == 1) {
                if (e - b - 1 < k) return false;
                b = e;
            }
        }
        return true;
    }
};
