class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for (int i = 1; i <= n; ++i) {
            if (!(i % 3) && !(i % 5)) result.push_back("FizzBuzz");
            else if (!(i % 5)) result.push_back("Buzz");
            else if (!(i % 3)) result.push_back("Fizz");
            else result.push_back(itos(i));
        }
        return result;
    }
    string itos(int i) {
        stringstream ss;
        ss << i;
        return ss.str();
    }
};
