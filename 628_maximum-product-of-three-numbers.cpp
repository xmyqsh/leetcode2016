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

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        for (auto num : nums) {
            if (num <= min1) {
                min2 = min1;
                min1 = num;
            } else if (num < min2) {
                min2 = num;
            }
            if (num >= max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (num >= max2) {
                max3 = max2;
                max2 = num;
            } else if (num > max3) {
                max3 = num;
            }
        }
        return max(min1 * min2 * max1, max3 * max2 * max1);
    }
};
