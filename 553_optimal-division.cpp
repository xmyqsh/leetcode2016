class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if (nums.size() == 1) return to_string(nums[0]);
        stringstream ss;
        if (nums.size() == 2) {
            ss << nums[0] << '/' << nums[1];
            return ss.str();
        }
        ss << nums[0] << "/(" << nums[1];
        for (int i = 2; i != nums.size(); ++i)
            ss << '/' << nums[i];
        ss << ')';
        return ss.str();
    }
};
