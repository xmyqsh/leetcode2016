/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }

    void addNum(int val) {
        int index = binarySearch(val);
        if (index != -1 && intervals[index].end >= val) return;
        if (index != intervals.size() - 1 && val + 1 == intervals[index + 1].start) {
            intervals[index + 1].start = val;
            if (index != -1 && intervals[index].end + 1 == intervals[index + 1].start) {
                intervals[index].end = intervals[index + 1].end;
                intervals.erase(intervals.begin() + index + 1);
            }
        } else if (index != -1 && val == intervals[index].end + 1) intervals[index].end = val;
        else intervals.insert(intervals.begin() + index + 1, Interval(val, val));
    }

    vector<Interval> getIntervals() {
        return intervals;
    }
private:
    int binarySearch(int val) {
        int b = 0, e = intervals.size() - 1;
        while (b <= e) {
            const int mid = b + (e - b) / 2;
            if (intervals[mid].start > val) e = mid - 1;
            else b = mid + 1;
        }
        return e;
    }
    
private:
    vector<Interval> intervals;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
