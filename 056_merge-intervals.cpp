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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if (intervals.empty()) return result;
        result.reserve(intervals.size());
        sort(intervals.begin(), intervals.end(), IntervalCmp());
        Interval cur(intervals[0].start, intervals[0].end);
        for (int i = 1; i < intervals.size(); ++i) {
            if (cur.end < intervals[i].start) {
                result.push_back(cur);
                cur.start = intervals[i].start;
                cur.end = intervals[i].end;
            } else {
                cur.end = max(cur.end, intervals[i].end);
            }
        }
        result.push_back(cur);
        return result;
    }
    /*static bool IntervalCmp(Interval& i1, Interval& i2) {
        return i1.start == i2.start ? i1.end < i2.end : i1.start < i2.start;
    }*/
    struct IntervalCmp {
        bool operator()(const Interval& i1, const Interval& i2) {
            return i1.start == i2.start ? i1.end < i2.end : i1.start < i2.start;
        }
    };
};
