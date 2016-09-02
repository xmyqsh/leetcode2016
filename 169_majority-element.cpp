class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result, count = 0;
        for (auto num : nums) {
            if (count == 0) {
                result = num;
                count = 1;
            } else if (num == result) ++count;
            else --count;
        }
        return result;
    }
};
