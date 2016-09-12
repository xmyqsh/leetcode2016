class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        result.reserve(digits.size() + 1);
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            const int sum = digits[i] + carry;
            result.push_back(sum % 10);
            carry = sum / 10;
        }
        if (carry) result.push_back(1);
        reverse(result.begin(), result.end());
        return result;
    }
};
