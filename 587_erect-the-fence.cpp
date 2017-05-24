/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    vector<Point> outerTrees(vector<Point>& points) {
        if (points.size() < 4) return points;
        sort(points.begin(), points.end(), [](const Point& p1, const Point& p2) {
            return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
        });
        vector<Point> result;
        for (auto& point : points) {
            while (result.size() >= 2 && orientation(result[result.size() - 2], result[result.size() - 1], point) < 0)
                result.pop_back();
            result.push_back(point);
        }
        result.pop_back();
        for (auto iter = points.rbegin(); iter != points.rend(); ++iter) {
            while (result.size() >= 2 && orientation(result[result.size() - 2], result[result.size() - 1], *iter) < 0)
                result.pop_back();
            result.push_back(*iter);
        }
        result.pop_back();
        return result;
    }
    int orientation(const Point& p1, const Point& p2, const Point& p3) {
        return (p3.y - p2.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p3.x - p2.x);
    }
};

/*
(x1, y1), (x2, y2), (x3, y3)
(y3 - y2) / (x3 - x2) > (y2 - y1) / (x2 - x1)
(y3 - y2) * (x2 - x1) > (y2 - y1) * (x3 - x2)
*/
