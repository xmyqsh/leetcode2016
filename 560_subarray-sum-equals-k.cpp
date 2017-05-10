class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> record;
        int result = 0, cum = 0;
        ++record[0];
        for (auto num : nums) {
            cum += num;
            result += record[cum - k];
            ++record[cum];
        }
        return result;
    }
};
