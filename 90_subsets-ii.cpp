class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> path;
        sort(nums.begin(), nums.end());
        travel(&result, path, nums, 0);
        return result;
    }
    void travel(vector<vector<int> >* result, vector<int>& path, const vector<int>& nums, int cur) {
        result->push_back(path);
        for (int i = cur; i < nums.size(); ++i) {
            if (i != cur && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            travel(result, path, nums, i + 1);
            path.pop_back();
        }
    }
};
