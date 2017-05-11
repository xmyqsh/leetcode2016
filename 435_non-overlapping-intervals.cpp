/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if (intervals.size() < 2) return 0;
        sort(intervals.begin(), intervals.end(), [](const Interval& i1, const Interval& i2) {
            return i1.start < i2.start || (i1.start == i2.start && i1.end < i2.end);
        });
        int cnt = 0, e = intervals[0].end;
        for (int i = 1; i != intervals.size(); ++i) {
            if (e <= intervals[i].start) {
                e = intervals[i].end;
            } else {
                ++cnt;
                e = min(e, intervals[i].end);
            }
        }
        return cnt;
    }
};
