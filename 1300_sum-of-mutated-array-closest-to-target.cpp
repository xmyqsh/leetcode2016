// Nlog(N) + log(maxValue)log(N)
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<int> suffixSum(arr.size(), 0);
        suffixSum[arr.size() - 1] = arr[arr.size() - 1];
        for (int i = arr.size() - 2; i != -1; --i) suffixSum[i] = arr[i] + suffixSum[i + 1];
        unordered_map<int, int> mp;
        int b = 0, e = arr[arr.size() - 1];
        while (b < e) {
            const int mid = (b + e) / 2;
            if (getV(mp, mid - 1, arr, suffixSum, target) <= getV(mp, mid, arr, suffixSum, target)) e = mid - 1;
            else if (getV(mp, mid, arr, suffixSum, target) > getV(mp, mid + 1, arr, suffixSum, target)) b = mid + 1;
            else return mid;
        }
        return b;
    }
    int getV(unordered_map<int, int>& mp, int value, const vector<int>& arr, const vector<int>& suffixSum, int target) {
        if (mp.count(value)) return mp[value];
        int b = 0, e = arr.size() - 1;
        while (b != e) {
            const int mid = (b + e) / 2;
            if (arr[mid] <= value) b = mid + 1;
            else e = mid;
        }
        mp[value] = suffixSum[0] - suffixSum[b] + value * (arr.size() - b);
        mp[value] = abs(mp[value] - target);
        return mp[value];
    }
};
