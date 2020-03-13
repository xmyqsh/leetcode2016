class Solution {
public:
    vector<int> closestDivisors(int num) {
        auto [l1, r1] = makeProd(num + 1);
        auto [l2, r2] = makeProd(num + 2);
        if (abs(l1 - r1) < abs(l2 - r2)) return {l1, r1};
        return {l2, r2};
    }
    tuple<int, int> makeProd(int num) {
        for (int i = sqrt(num); i != 1; --i) {
            if ((num % i) == 0) return tuple(num / i, i);
        }
        return tuple(1, num);
    }
};
