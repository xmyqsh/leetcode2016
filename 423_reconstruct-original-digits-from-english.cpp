class Solution {
public:
    string originalDigits(string s) {
        vector<int> count(255, 0);
        vector<int> nums(10);
        for (auto ch : s) ++count[ch];
        // "zero"
        nums[0] = count['z'];
        count['o'] -= nums[0];
        // "two"
        nums[2] = count['w'];
        count['t'] -= nums[2];
        count['o'] -= nums[2];
        // "four"
        nums[4] = count['u'];
        count['f'] -= nums[4];
        count['o'] -= nums[4];
        // "six"
        nums[6] = count['x'];
        count['i'] -= nums[6];
        // "eight"
        nums[8] = count['g'];
        count['i'] -= nums[8];
        count['t'] -= nums[8];
        // "one"
        nums[1] = count['o'];
        // "three"
        nums[3] = count['t'];
        // "five"
        nums[5] = count['f'];
        count['i'] -= nums[5];
        count['v'] -= nums[5];
        // "seven"
        nums[7] = count['v'];
        // "nine"
        nums[9] = count['i'];

        string ret;
        for (int i = 0; i != 10; ++i)
            ret.append(string(nums[i], i + '0'));
        return ret;
    }
};

/*
zero one two three four five six seven eight nine

z -> zero  e r o
w -> two   t o
u -> four  f o r
x -> six   s i
g -> eight e i h t

o -> one   n e
t -> three h r e
f -> five  i v e


v -> seven s e n
i -> nine  n e

*/
