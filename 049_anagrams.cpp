class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > mp;
        for (int i = 0; i < strs.size(); ++i) {
            string key = strs[i];
            sort(key.begin(), key.end());
            mp[key].push_back(strs[i]);
        }
        vector<vector<string> > result;
        for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
            sort(iter->second.begin(), iter->second.end());
            result.push_back(vector<string>(iter->second.begin(), iter->second.end()));
        }
        return result;
    }
};
