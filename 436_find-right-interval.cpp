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
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> hash;
        for (int i = 0; i != intervals.size(); ++i)
            hash[intervals[i].start] = i;
        vector<int> result;
        for (auto& interval : intervals) {
            auto iter = hash.lower_bound(interval.end);
            if (iter == hash.end())
                result.push_back(-1);
            else
                result.push_back(iter->second);
        }
        return result;
    }
};
