class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal)
            return false;
        unsigned int used = (1 << maxChoosableInteger) - 1;
        unordered_map<unsigned int, bool> cache;
        return travel(cache, used, maxChoosableInteger, desiredTotal);
    }
    bool travel(unordered_map<unsigned, bool>& cache, unsigned int used, int size, int target) {
        if (cache.count(used)) return cache[used];
        if (target <= size && used >= (1 << (target - 1))) return true;
        for (unsigned int i = 1, bit = 1; i <= size; ++i, bit <<= 1) {
            if ((used & bit) == 0) continue;
            if (cache[used] = !travel(cache, (used ^ bit), size, target - i))
                return true;
        }
        return false;
    }
};
