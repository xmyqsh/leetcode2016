class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int attemps = minutesToTest / minutesToDie;
        int pigs = log(buckets) / log(attemps + 1);
        return pow(attemps + 1, pigs) == buckets ? pigs : pigs + 1;
    }
};
