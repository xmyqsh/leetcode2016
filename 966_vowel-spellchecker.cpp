class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string, string> uncap;
        unordered_map<string, string> rmvowel;
        unordered_set<string> st;
        string vowel("aeiou");
        for (auto word : wordlist) {
            st.insert(word);
            string lower_word = str_tolower(word);
            if (!uncap.count(lower_word)) uncap[lower_word] = word;
            string rm_word = rm_vowel(lower_word, vowel);
            if (!rmvowel.count(rm_word)) rmvowel[rm_word] = word;
        }
        vector<string> result; result.reserve(queries.size());
        for (auto query : queries) {
            if (st.count(query)) {
                result.push_back(query);
                continue;
            }
            query = str_tolower(query);
            if (uncap.count(query)) {
                result.push_back(uncap[query]);
                continue;
            }
            query = rm_vowel(query, vowel);
            if (rmvowel.count(query)) {
                result.push_back(rmvowel[query]);
                continue;
            }
            result.push_back("");
        }
        return result;
    }
    string str_tolower(string s) {
        std::transform(s.begin(), s.end(), s.begin(),
                       [](unsigned char c){ return std::tolower(c); }
                      );
        return s;
    }
    string rm_vowel(string s, const string& vowel) {
        std::transform(s.begin(), s.end(), s.begin(),
                       [&vowel](unsigned char c){ return vowel.find(c, 0) == string::npos ? c : ' '; }
                      );
        return s;
    }
};
