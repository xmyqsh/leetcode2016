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
