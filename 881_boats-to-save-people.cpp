class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int b = 0, e = people.size() - 1;
        int ret = 0;
        for (; b < e; ) {
            if (people[b] + people[e] > limit) {
                --e;
            } else {
                ++b; --e;
            }
            ++ret;
        }
        if (b == e) ++ret;
        return ret;
    }
};
