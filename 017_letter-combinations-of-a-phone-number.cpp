class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> mp(10);
        mp[0] = "";
        mp[1] = "";
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        vector<string> result;
        if (digits.empty()) return result;
        result.push_back("");
        for (int i = 0; i < digits.size(); ++i) {
            const int num = digits[i] - '0';
            if (mp[num].empty()) break;
            vector<string> tmp;
            for (int j = 0; j < result.size(); ++j) {
                for (int k = 0; k < mp[num].size(); ++k) {
                    tmp.push_back(result[j] + mp[num][k]);
                }
            }
            swap(tmp, result);
        }
        return result;
    }
};
