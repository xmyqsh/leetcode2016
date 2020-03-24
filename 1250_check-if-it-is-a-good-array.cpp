class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int ret = nums[0];
        for (auto c : nums) {
            ret = gcd(ret, c);
        }
        return ret == 1;
    }
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
};
