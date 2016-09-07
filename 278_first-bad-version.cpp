// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int b = 1, e = n;
        while (b <= e) {
            const int mid = b + (e - b) / 2;
            if (isBadVersion(mid)) e = mid - 1;
            else b = mid + 1;
        }
        return b;
    }
};
