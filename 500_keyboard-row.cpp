class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> row1{'q', 'w', 'e', 'r', 't', 'y','u', 'i', 'o', 'p'};
        unordered_set<char> row2{'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        unordered_set<char> row3{'z', 'x', 'c', 'v', 'b' ,'n', 'm'};
        vector<unordered_set<char> > row{row1, row2, row3};
        vector<string> result;
        for (auto& word : words) {
            for (int i = 0; i != 3; ++i) {
                int j = 0;
                for (; j != word.size(); ++j)
                    if (!row[i].count((char)tolower(word[j])))
                        break;
                if (j == word.size()) {
                    result.push_back(word);
                    break;
                }
            }
        }
        return result;
    }
};
