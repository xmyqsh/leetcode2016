class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty()) return result;
        int b = nums[0], e = nums[0];
        for (int i = 1; i <= nums.size(); ++i) {
            if (i != nums.size() && nums[i] == e + 1) e = nums[i];
            else {
                ostringstream ss;
                ss << b;
                if (b != e) ss << "->" << e;
                result.push_back(ss.str());
                if (i != nums.size()) b = nums[i], e = nums[i];
            }
        }
        return result;
    }
};
