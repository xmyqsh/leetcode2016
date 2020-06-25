// O(N*S)
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int, int> sum2len;
        sum2len[0] = 0;
        for (auto rod : rods) {
            unordered_map<int, int> update;
            for (const auto& item : sum2len) {
                auto sum = item.first, len = item.second;
                // add to left
                update[sum + rod] = max(update[sum + rod], len + rod);
                // add to right
                update[sum - rod] = max(update[sum - rod], len);
                // discard
                update[sum]       = max(update[sum],       len);
            }
            swap(sum2len, update);
        }
        return sum2len[0];
    }
};
