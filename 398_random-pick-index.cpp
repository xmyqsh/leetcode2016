class Solution {
public:
    Solution(vector<int> nums) {
        swap(this->nums, nums);
    }
    
    int pick(int target) {
        int cnt = 0, result;
        for (int i = 0; i != nums.size(); ++i) {
            if (nums[i] == target) {
                ++cnt;
                if (rand() % cnt == 0) result = i;
            }
        }
        return result;
    }
private:
    vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
