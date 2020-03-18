class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int zero = 0;
        for (auto n : arr) if (n == 0) ++zero;
        if (zero > 1) return true;
        for (int i = 0; i != arr.size(); ++i) {
            if (arr[i] == 0) continue;
            int target = 2 * arr[i];
            for (int j = arr.size() - 1; j != -1; --j) {
                if (arr[j] == target) return true;
            }
        }
        return false;
    }
};
