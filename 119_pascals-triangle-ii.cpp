class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(1, 1);
        while (rowIndex--) {
            result.push_back(1);
            for (int i = result.size() - 2; i > 0; --i)
                result[i] += result[i - 1];
        }
        return result;
    }
};
