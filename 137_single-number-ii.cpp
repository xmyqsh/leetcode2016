class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0, three = 0;
        for (auto num : nums) {
            two |= (one & num);
            one ^= num;
            // 3 = 1 + 2
            three = ~(one & two);
            one &= three;
            two &= three;
        }
        return one;
    }
};

// straight forward version
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unsigned int bitsOne = 0, bitsTwo = 0, bitsThree = 0;
        for (unsigned int n : nums) {
            unsigned int hasOne = ~(bitsOne | bitsTwo | bitsThree) & n;
            unsigned int hasTwo = bitsOne & n;
            unsigned int hasThree = bitsTwo & n;
            unsigned int hasForth = bitsThree & n;
            bitsOne &= ~hasTwo;
            bitsOne |= (hasOne | hasForth);
            bitsTwo &= ~hasThree;
            bitsTwo |= hasTwo;
            bitsThree &= ~hasForth;
            bitsThree |= hasThree;
            //assert((bitsOne & bitsTwo & bitsThree) == 0);
        }
        return bitsOne;
    }
};
