class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> path;
        sort(nums.begin(), nums.end());
        travel(&result, path, nums, 0);
        return result;
    }
    void travel(vector<vector<int> >* result, vector<int>& path, const vector<int>& nums, int cur) {
        if (cur == nums.size()) {
            result->push_back(path);
            return;
        }
        travel(result, path, nums, cur + 1);
        path.push_back(nums[cur]);
        travel(result, path, nums, cur + 1);
        path.pop_back();
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> path;
        sort(nums.begin(), nums.end());
        travel(&result, path, nums, 0);
        return result;
    }
    void travel(vector<vector<int> >* result, vector<int>& path, const vector<int>& nums, int cur) {
        result->push_back(path);
        for (int i = cur; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            travel(result, path, nums, i + 1);
            path.pop_back();
        }
    }
};
