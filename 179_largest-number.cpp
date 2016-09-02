class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strNum;
        strNum.reserve(nums.size());
        for (auto num : nums) strNum.push_back(to_string(num));
        sort(strNum.begin(), strNum.end(),
                [](const string& str1, const string& str2) {
                    return str1 + str2 > str2 + str1;
                });
        stringstream ss;
        for (auto sn : strNum) ss << sn;
        string result = ss.str();
        return result[0] == '0' ? "0" : result;
    }
};
