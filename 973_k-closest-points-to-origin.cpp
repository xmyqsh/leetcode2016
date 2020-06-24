// O(NlogN)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), [](const auto& p1, const auto& p2) {
            return p1[0] * p1[0] + p1[1] * p1[1] < p2[0] * p2[0] + p2[1] * p2[1];
        });
        return {points.begin(), points.begin() + K};
    }
};

// O(N)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int b = 0, e = points.size() - 1;
        int idx = b;
        while (idx != K) {
            auto& pivot = points[e];
            idx = b;
            for (int i = b; i != e; ++i) {
                if (cmp(points[i], pivot)) swap(points[i], points[idx++]);
            }
            swap(pivot, points[idx]);
            if (idx + 1 < K) b = idx + 1;
            else if (idx + 1 > K) e = idx - 1;
            else break;
        }
        return {points.begin(), points.begin() + K};
    }
    bool cmp(const vector<int>& p1, const vector<int>& p2) {
        return p1[0] * p1[0] + p1[1] * p1[1] <= p2[0] * p2[0] + p2[1] * p2[1];
    };
};
