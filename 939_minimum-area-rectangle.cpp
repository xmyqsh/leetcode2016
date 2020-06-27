class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map<int, set<int>> xy;
        for (const auto& point : points) {
            int x = point[0], y = point[1];
            xy[x].insert(y);
        }
        vector<int> xs; xs.reserve(xy.size());
        for (const auto& item : xy) if (item.second.size() > 1) xs.push_back(item.first);
        if (xs.empty()) return 0;
        int area = INT_MAX;
        for (int i = 0; i + 1 != xs.size(); ++i) {
            const auto& st1 = xy[xs[i]];
            for (int j = i + 1; j != xs.size(); ++j) {
                const auto& st2 = xy[xs[j]];
                vector<int> v_intersection;
                set_intersection(st1.begin(), st1.end(),
                                 st2.begin(), st2.end(),
                                 back_inserter(v_intersection));
                if (v_intersection.size() <= 1) continue;
                //sort(v_intersection.begin(), v_intersection.end());
                int dx = xs[j] - xs[i];
                int dy = INT_MAX;
                for (int k = 1; k != v_intersection.size(); ++k) {
                    dy = min(dy, v_intersection[k] - v_intersection[k - 1]);
                }
                area = min(area, dx * dy);
            }
        }
        return area == INT_MAX ? 0 : area;
    }
};
