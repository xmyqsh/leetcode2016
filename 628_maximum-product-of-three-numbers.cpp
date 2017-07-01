class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        vector<int> positive, negtive;
        for (auto num : nums) {
            if (num > 0) positive.push_back(num);
            else if (num < 0) negtive.push_back(num);
        }
        if (positive.size() + negtive.size() < 3) return 0;
        sort(positive.begin(), positive.end());
        sort(negtive.begin(), negtive.end());
        if (positive.size() == 0)
            return negtive[negtive.size() - 1] * negtive[negtive.size() - 2] * negtive[negtive.size() - 3];
        if (negtive.size() < 2)
            return positive[positive.size() - 1] * positive[positive.size() - 2] * positive[positive.size() - 3];
        return positive[positive.size() - 1] * max(positive[positive.size() - 2] * positive[positive.size() - 3],
                                                    negtive[0] * negtive[1]);
    }
};
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return max(nums[0] * nums[1] * nums[nums.size() - 1],
                   nums[nums.size() - 3] * nums[nums.size() - 2] * nums[nums.size() - 1]);
    }
};
