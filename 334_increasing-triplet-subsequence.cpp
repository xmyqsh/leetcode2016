class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        vector<int> tail(3);
        tail[0] = nums[0];
        int e = 0;
        for (int i = 1; i != nums.size(); ++i) {
            if (nums[i] <= tail[0]) tail[0] = nums[i];
            else if (nums[i] > tail[e]) tail[++e] = nums[i];
            else tail[1] = min(tail[1], nums[i]);
            if (e == 2) return true;
        }
        return false;
    }
};
