class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        nextPermutation(str);
        long result = stol(str);
        if (result <= n || result > INT_MAX)
            return -1;
        return result;
    }
    void nextPermutation(string& str) {
        int n = str.size();
        int x, y;
        for (x = n - 2; x >= 0 && str[x] >= str[x + 1]; --x);
        if (x < 0) {
            reverse(str.begin(), str.end());
            return;
        }
        for (y = n - 1; str[y] <= str[x]; --y);
        swap(str[x], str[y]);
        reverse(str.begin() + x + 1, str.end());
    }    
};
