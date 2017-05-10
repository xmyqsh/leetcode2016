class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        unsigned int mask = 1;
        int result = 0;
        for (int i = 0; i != 32; ++i) {
            int ones = 0, zeros = 0;
            for (auto num : nums)
                if (mask & num) ++ones;
                else ++zeros;
            result += ones * zeros;
            mask <<= 1;
        }
        return result;
    }
};

/*
4   0100
14  1110
2   0010

6
*/
