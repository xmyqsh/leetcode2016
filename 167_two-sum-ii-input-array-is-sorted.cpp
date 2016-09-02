class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result(2);
        int b = 0, e = numbers.size() - 1;
        while (b < e) {
            const int sum = numbers[b] + numbers[e];
            if (sum < target) ++b;
            else if (sum > target) --e;
            else {
                result[0] = b + 1;
                result[1] = e + 1;
                break;
            }
        }
        return result;
    }
};
