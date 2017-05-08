class Solution {
public:
    string nearestPalindromic(string n) {
        int l = n.size();
        set<long> candidates;
        candidates.insert(pow((long)10, l) + 1);
        candidates.insert(pow((long)10, l - 1) - 1);
        long prefix = stol(n.substr(0, (l + 1) / 2));
        for (long i = -1; i <= 1; ++i) {
            string p = to_string(prefix + i);
            string pp = p + string(p.rbegin() + (l & 1), p.rend());
            candidates.insert(stol(pp));
        }
        long num = stol(n), minDiff = LONG_MAX, minVal;
        candidates.erase(num);
        for (long candidate : candidates) {
            long diff = abs(candidate - num);
            if (diff < minDiff) {
                minDiff = diff;
                minVal = candidate;
            }
        }
        return to_string(minVal);
    }
};
