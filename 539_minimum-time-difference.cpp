class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end(), [](const string& s1, const string& s2) {
            int h1 = stoi(s1.substr(0, 2)), h2 = stoi(s2.substr(0, 2));
            if (h1 < h2) return true;
            if (h1 > h2) return false;
            int m1 = stoi(s1.substr(3, 2)), m2 = stoi(s2.substr(3, 2));
            return m1 < m2;
        });
        int result = 24 * 60, n = timePoints.size();
        timePoints.push_back(timePoints[0]);
        if (timePoints[n][1] > '5') {
            timePoints[n][0] += 3;
            timePoints[n][1] += 4 - 10;
        } else {
            timePoints[n][0] += 2;
            timePoints[n][1] += 4;
        }
        for (int i = 0; i != n; ++i)
            result = min(result, gap(timePoints[i], timePoints[i + 1]));
        return result;
    }
    int gap(const string& s1, const string& s2) {
        int h1 = stoi(s1.substr(0, 2)), h2 = stoi(s2.substr(0, 2));
        int m1 = stoi(s1.substr(3, 2)), m2 = stoi(s2.substr(3, 2));
        return (h2 - h1) * 60 + m2 - m1;
    }
};
