class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = INT_MAX;
        for (int b = 0, e = 0, sum = 0; e < nums.size(); ) {
            while (e < nums.size() && sum < s) sum += nums[e++];
            while (sum >= s) {
                result = min(result, e - b);
                sum -= nums[b++];
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};
