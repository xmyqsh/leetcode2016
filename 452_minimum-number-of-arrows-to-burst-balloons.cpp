class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second);
        });
        int cnt = 1, e = points[0].second;
        for (int i = 1; i != points.size(); ++i) {
            if (e < points[i].first) {
                ++cnt;
                e = points[i].second;
            } else {
                e = min(e, points[i].second);
            }
        }
        return cnt;
    }
};
