class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int leftFirstVal = INT_MAX, leftSecondVal = INT_MAX, leftFirstIdx, leftSecondIdx;
        int rightFirstVal = INT_MIN, rightSecondVal = INT_MIN, rightFirstIdx, rightSecondIdx;
        for (int i = 0; i != arrays.size(); ++i) {
            if (arrays[i].empty()) continue;
            if (arrays[i][0] <= leftFirstVal) {
                leftSecondVal = leftFirstVal;
                leftSecondIdx = leftFirstIdx;
                leftFirstVal = arrays[i][0];
                leftFirstIdx = i;
            } else if (arrays[i][0] < leftSecondVal) {
                leftSecondVal = arrays[i][0];
                leftSecondIdx = i;
            }
            if (arrays[i][arrays[i].size() - 1] >= rightFirstVal) {
                rightSecondVal = rightFirstVal;
                rightSecondIdx = rightFirstIdx;
                rightFirstVal = arrays[i][arrays[i].size() - 1];
                rightFirstIdx = i;
            } else if (arrays[i][arrays[i].size() - 1] > rightSecondVal) {
                rightSecondVal = arrays[i][arrays[i].size() - 1];
                rightSecondIdx = i;
            }
        }
        if (leftFirstIdx == rightFirstIdx)
            return max(rightFirstVal - leftSecondVal, rightSecondVal - leftFirstVal);
        return rightFirstVal - leftFirstVal;
    }
};
