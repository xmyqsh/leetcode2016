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
    int maxPoints(vector<Point>& points) {
        if (points.size() < 3) return points.size();
        int result = 0;
        for (int i = 0; i < points.size() - result; ++i) {
            int nSame = 1;
            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i].x == points[j].x || points[i].y == points[j].y) {
                    ++nSame;
                    continue;
                }
                int nLine = 1;
                for (int k = j + 1; k < points.size(); ++k) {
                    const int a = (points[i].x - points[k].x) * (points[j].y - points[k].y);
                    const int b = (points[i].y - points[k].y) * (points[j].x - points[k].x);
                    if (a == b) ++nLine;
                }
                result = max(result, nSame + nLine);
            }
            result = max(result, nSame);
        }
        return result;
    }
};
