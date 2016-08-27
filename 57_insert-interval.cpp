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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if (intervals.empty()) return vector<Interval>(1, newInterval);
        vector<Interval> result;
        result.reserve(intervals.size() + 1);
        int idx = 0;
        while (idx < intervals.size() && intervals[idx].end < newInterval.start)
            result.push_back(intervals[idx++]);
        if (idx < intervals.size()) {
            newInterval.start = min(newInterval.start, intervals[idx].start);
        } else {
            result.push_back(newInterval);
            return result;
        }
        while (idx < intervals.size() && intervals[idx].start <= newInterval.end)
            ++idx;
        newInterval.end = max(newInterval.end, intervals[idx - 1].end);
        result.push_back(newInterval);
        while (idx < intervals.size())
            result.push_back(intervals[idx++]);
        return result;
    }
};
