class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        int minX = INT_MAX, maxX = INT_MIN;
        unordered_map<int, unordered_set<int> > mp;
        for (auto point : points) {
            minX = min(minX, point.first);
            maxX = max(maxX, point.first);
            mp[point.first].insert(point.second);
        }
        int midXmTwo = maxX + minX;
        for (auto point : points) {
            int reflectX = midXmTwo - point.first;
            if (!mp.count(reflectX) || !mp[reflectX].count(point.second))
                return false;
        }
        return true;
    }
};
