class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        if (points.size() < 3) return 0;
        int result = 0;
        for (int i = 0; i != points.size(); ++i) {
            unordered_map<long, int> mp;
            for (int j = 0; j != points.size(); ++j) {
                if (i == j) continue;
                ++mp[distance(points[i], points[j])];
            }
            for (unordered_map<long, int>::iterator iter = mp.begin(); iter != mp.end(); ++iter)
                    result += iter->second * (iter->second - 1);
        }
        return result;
    }
    long distance(const pair<int, int>& point1, const pair<int, int>& point2) {
        long dx = point1.first - point2.first;
        long dy = point1.second - point2.second;
        return dx * dx + dy * dy;
    }
};
