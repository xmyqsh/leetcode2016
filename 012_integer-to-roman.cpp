class Solution {
public:
    string intToRoman(int num) {
        string THOUS[] = {"", "M", "MM", "MMM"};
        string HUNDS[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string TENS[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string ONES[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return THOUS[(int)(num / 1000) % 10] + HUNDS[(int)(num / 100) % 10] + TENS[(int)(num / 10) % 10] + ONES[num % 10];
    }
};
