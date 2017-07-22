class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int key = encode(needs);
        if (key == 0) return 0;
        if (cache.count(key)) return cache[key];
        
        int result = INT_MAX;
        for (int i = 0; i != price.size(); ++i) {
            if (needs[i] > 0) {
                --needs[i];
                result = min(result, shoppingOffers(price, special, needs) + price[i]);
                ++needs[i];
            }
        }

        for (auto& sp : special) {
            int i;
            for (i = 0; i != needs.size(); ++i) if (needs[i] < sp[i]) break;
            if (i != needs.size()) continue;
            for (i = 0; i != needs.size(); ++i) needs[i] -= sp[i];
            result = min(result, shoppingOffers(price, special, needs) + sp.back());
            for (i = 0; i != needs.size(); ++i) needs[i] += sp[i];
        }
        
        return cache[key] = result;
    }
    int encode(const vector<int>& needs) {
        int key = 0;
        for (auto need : needs) {
            key <<= 3;
            key += need;
        }
        return key;
    }
private:
    unordered_map<int, int> cache;
};
