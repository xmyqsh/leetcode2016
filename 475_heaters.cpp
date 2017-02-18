class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if (heaters.size() == 1)
            return max(heaters[0] - houses[0], houses[houses.size() - 1] - heaters[0]);
        sort(heaters.begin(), heaters.end());
        int ret = 0;
        for (auto house : houses) {
            int cur = INT_MAX;
            auto pos = lower_bound(heaters.begin(), heaters.end(), house);
            if (pos != heaters.end()) cur = min(cur, *pos - house);
            if (pos != heaters.begin()) cur = min(cur, house - *(pos - 1));
            ret = max(ret, cur);
        }
        return ret;
        
    }
};
