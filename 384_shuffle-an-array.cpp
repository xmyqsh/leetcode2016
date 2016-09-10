class Solution {
public:
    Solution(vector<int> nums) {
        this->nums.reserve(nums.size());
        this->shuf.reserve(nums.size());
        for (auto num : nums) {
            this->nums.push_back(num);
            this->shuf.push_back(num);
        }
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        for (int i = 0; i != nums.size(); ++i) shuf[i] = nums[i];
        return shuf;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = shuf.size() - 1; i > 0; --i)
            swap(shuf[rand() % (i + 1)], shuf[i]);
        return shuf;
    }
private:
    vector<int> nums, shuf;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
