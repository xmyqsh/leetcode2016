class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > result;
        if (nums.empty()) return result;
        sort(nums.begin(), nums.end());
        travel(&result, nums, 0);
        return result;
    }
    void travel(vector<vector<int> >* result, vector<int> nums, int cur) {
        if (cur == nums.size() - 1) {
            result->push_back(nums);
            return;
        }
        for (int i = cur; i < nums.size(); ++i) {
            if (i != cur && nums[i] == nums[cur]) continue;
            swap(nums[i], nums[cur]);
            travel(result, nums, cur + 1);
            //swap(nums[i], nums[cur]);
        }
    }
};
