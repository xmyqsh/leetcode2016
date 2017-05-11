class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false;
        int sum = 1;
        for (int i = sqrt(num); i != 1; --i)
            if (!(num % i))
                sum += i + num / i;
        return sum == num;
    }
};
