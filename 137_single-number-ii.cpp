class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0, three = 0;
        for (auto num : nums) {
            two |= (one & num);
            one ^= num;
            three = ~(one & two);
            one &= three;
            two &= three;
        }
        return one;
    }
};
