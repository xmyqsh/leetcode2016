class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        while (!st.count(n)) {
            st.insert(n);
            int powSum = 0;
            while (n) {
                int tmp = n % 10;
                powSum += tmp * tmp;
                n /= 10;
            }
            n = powSum;
        }
        return n == 1;
    }
};
