class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        sort(A.begin(), A.end());
        unordered_map<int, int> mp;
        for (auto a : A) ++mp[a];
        for (auto a : A) {
            if (mp.count(a)) {
                if (a < 0) {
                    if (!mp.count(a / 2)) return false;
                    if (--mp[a] == 0) mp.erase(a);
                    if (--mp[a / 2] == 0) mp.erase(a / 2);
                } else {
                    if (!mp.count(a * 2)) return false;
                    if (--mp[a] == 0) mp.erase(a);
                    if (--mp[a * 2] == 0) mp.erase(a * 2);
                }
            }
        }
        return true;
    }
};
