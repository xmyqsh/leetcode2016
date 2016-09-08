class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "aeiouAEIOU";
        int b = 0, e = s.size() - 1;
        while (vowels.find(s[b]) == string::npos) ++b;
        while (vowels.find(s[e]) == string::npos) --e;
        while (b < e) {
            swap(s[b++], s[e--]);
            while (vowels.find(s[b]) == string::npos) ++b;
            while (vowels.find(s[e]) == string::npos) --e;
        }
        return s;
    }
};
