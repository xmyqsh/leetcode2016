class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        int cnt = 0;
        for (int i = 0; i != flowerbed.size(); ++i) {
            if (flowerbed[i] == 0) {
                if ((i == 0 || flowerbed[i - 1] == 0) && (i + 1 == flowerbed.size() || flowerbed[i + 1] == 0)) {
                    flowerbed[i] = 1;
                    ++cnt;
                }
            }
        }
        return cnt >= n;
    }
};
