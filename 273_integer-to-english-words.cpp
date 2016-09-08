class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        return int_string(num).substr(1);
    }
private:
    static string int_string(int num) {
        if (num >= 1000000000)      return int_string(num / 1000000000) + " Billion" + int_string(num % 1000000000);
        else if (num >= 1000000)    return int_string(num / 1000000) + " Million" + int_string(num % 1000000);
        else if (num >= 1000)       return int_string(num / 1000) + " Thousand" + int_string(num % 1000);
        else if (num >= 100)        return int_string(num / 100) + " Hundred" + int_string(num % 100);
        else if (num >= 20)         return string(" ") + below_100[num / 10 - 2] + int_string(num % 10);
        else if (num >= 1)          return string(" ") + below_20[num - 1];
        else return "";
    }
private:
    static const char* const below_20[];
    static const char* const below_100[];
};
const char* const Solution::below_20[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
const char* const Solution::below_100[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
