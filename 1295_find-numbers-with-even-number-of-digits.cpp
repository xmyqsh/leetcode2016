class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ret = 0;
        for (auto n : nums) {
            if (to_string(n).size() & 1) continue;
            ++ret;
        }
        return ret;
    }
};
