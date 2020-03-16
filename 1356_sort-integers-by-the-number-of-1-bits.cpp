class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        unordered_map<int, int> oneBits;
        for (auto n : arr) oneBits[n] = cntBits(n);
        sort(arr.begin(), arr.end(), [&](int n1, int n2) {
            return oneBits[n1] < oneBits[n2] ||
                  (oneBits[n1] == oneBits[n2] && n1 < n2);
        });
        return arr;
    }
    int cntBits(int n) {
        int cnt = 0;
        while (n) {
            n &= n - 1;
            ++cnt;
        }
        return cnt;
    }
};
