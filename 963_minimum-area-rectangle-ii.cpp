// O(N^2logN)
// TODO: compiler do not support hash vector<double>
class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        unordered_map<vector<double>, unordered_map<double, vector<vector<double>>>> drp;
        for (int i = 0; i + 1 != points.size(); ++i) {
            const auto& pi = points[i];
            for (int j = i; j != points.size(); ++j) {
                const auto& pj = points[j];
                auto [center, radius] = getCenterRadius(pi, pj);
                drp[center][radius].push_back(pi);
            }
        }
        for (const auto& centerItem : drp) {
            const auto& center = centerItem.first;
            for (const auto& radiusItem : centerItem.second) {
                const auto& radius = radiusItem.first;
                const auto& ps = radiusItem.second;
                for (int i = 0; i + 1 != ps.size(); ++i) {
                    for (int j = 0; j != ps.size(); ++j) {
                        area = min(area, getArea(center, radius, ps[i], ps[j]));
                    }
                }
            }
        }
        return area == FLT_MAX ? 0 : area;
    }
    tuple<vector<double>, double> getCenterRadius(const vector<double>& p1, const vector<double>& p2) {
        double cx = (p1[0] + p2[0]) / 2;
        double cy = (p1[1] + p2[1]) / 2;
        double radius = sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2)) / 2;
        return {{cx, cy}, radius};
    }
    double getArea(const vector<double>& center, double radius, const vector<double>& p1, const vector<double>& p2) {
        vector<double> p3({2 * center[0] - p1[0], 2 * center[1] - p1[1]});
        return getDist(p1, p3) * getDist(p2, p3);
    }
    double getDist(const vector<double>& p1, const vector<double>& p2) {
        return sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2));
    }
};

// O(N^3)
class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        if (points.size() < 4) return 0;
        unordered_map<int, unordered_set<int>> xy;
        for (const auto& point : points) xy[point[0]].insert(point[1]);
        double area = FLT_MAX;
        for (int i = 0; i + 2 != points.size(); ++i) {
            const auto& p1 = points[i];
            for (int j = i + 1; j + 1 != points.size(); ++j) {
                const auto& p2 = points[j];
                vector<int> v21({p2[0] - p1[0], p2[1] - p1[1]});
                for (int k = j + 1; k != points.size(); ++k) {
                    const auto& p3 = points[k];
                    vector<int> p4({p3[0] + v21[0], p3[1] + v21[1]});
                    if (!xy[p4[0]].count(p4[1])) continue;
                    vector<int> v31({p3[0] - p1[0], p3[1] - p1[1]});
                    if (dot(v21, v31) != 0) continue;
                    area = min(area, getArea(v21, v31));
                }
            }
        }
        return area == FLT_MAX ? 0 : area;
    }
    int dot(const vector<int>& v1, const vector<int>& v2) {
        return v1[0] * v2[0] + v1[1] * v2[1];
    }
    double getArea(const vector<int>& v1, const vector<int>& v2) {
        return getDist(v1) * getDist(v2);
    }
    double getDist(const vector<int>& v) {
        return sqrt(pow(v[0], 2) + pow(v[1], 2));
    }
};
/*
p2    p4

p1    p3

p3 - p1 + p2 - p1 = p4 - p1
p3 + p2 - p1 = p4

(p2 - p1) * (p3 - p1) == 0
*/
