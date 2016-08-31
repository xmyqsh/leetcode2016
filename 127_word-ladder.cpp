// bfs
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        unordered_map<string, int> len;
        len[beginWord] = 1;
        queue<string> q;
        for (q.push(beginWord); !q.empty(); q.pop()) {
            string word = q.front();
            int step = len[word] + 1;
            for (int i = 0; i < word.size(); ++i) {
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (word[i] != c) {
                        char tmp = word[i];
                        word[i] = c;
                        if (word == endWord) return step;
                        if (wordList.count(word) && !len.count(word)) {
                            len[word] = step;
                            q.push(word);
                        }
                        word[i] = tmp;
                    }
                }
            }
        }
        return 0;
    }
};

// BiDir-alike-bfs
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        unordered_set<string> word1;
        unordered_set<string> word2;
        word1.insert(beginWord);
        word2.insert(endWord);
        wordList.erase(beginWord);
        wordList.erase(endWord);
        return ladderLength(word1, word2, wordList, 1);
    }
    int ladderLength(unordered_set<string>& word1, unordered_set<string>& word2, unordered_set<string>& wordList, int level) {
        if (word1.empty()) return 0;
        if (word1.size() > word2.size()) return ladderLength(word2, word1, wordList, level);
        unordered_set<string> word3;
        for (auto iter = word1.begin(); iter != word1.end(); ++iter) {
            string word = *iter;
            for (auto ch = word.begin(); ch != word.end(); ++ch) {
                char tmp = *ch;
                for (*ch = 'a'; *ch <= 'z'; ++(*ch)) {
                    if (tmp != *ch) {
                        if (word2.count(word)) return level + 1;
                        if (wordList.count(word)) {
                            word3.insert(word);
                            wordList.erase(word);
                        }
                    }
                }
                *ch = tmp;
            }
        }
        return ladderLength(word2, word3, wordList, level + 1);
    }
};
