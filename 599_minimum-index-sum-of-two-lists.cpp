class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;
        for (int i = 0; i != list2.size(); ++i) mp[list2[i]] = i;
        vector<string> result;
        int leastIdxSum = list1.size() + list2.size();
        for (int i = 0; i != list1.size(); ++i) {
            if (!mp.count(list1[i])) continue;
            int idxSum = i + mp[list1[i]];
            if (leastIdxSum == idxSum) result.push_back(list1[i]);
            else if (leastIdxSum > idxSum) {
                result.clear();
                result.push_back(list1[i]);
                leastIdxSum = idxSum;
            }
        }
        return result;
    }
};
