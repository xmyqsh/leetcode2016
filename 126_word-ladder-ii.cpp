class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        unordered_map<string, vector<string> > nexts;
        vector<vector<string> > paths;
        vector<string> path;
        path.push_back(beginWord);
        unordered_set<string> word1, word2;
        word1.insert(beginWord);
        word2.insert(endWord);
        wordList.erase(beginWord);
        wordList.erase(endWord);
        if (findLadders(word1, word2, wordList, nexts, true))
            getPath(beginWord, endWord, nexts, paths, path);
        return paths;
    }
    bool findLadders(unordered_set<string>& word1,
                    unordered_set<string>& word2,
                    unordered_set<string> &wordList,
                    unordered_map<string, vector<string> >& nexts,
                    bool beginIsWord1) {
        if (word1.empty()) return false;
        if (word1.size() > word2.size())
            return findLadders(word2, word1, wordList, nexts, !beginIsWord1);
        for (auto iter = word1.begin(); iter != word1.end(); ++iter) wordList.erase(*iter);
        for (auto iter = word2.begin(); iter != word2.end(); ++iter) wordList.erase(*iter);
        unordered_set<string> word3;
        bool reach = false;
        for (auto iter = word1.begin(); iter != word1.end(); ++iter) {
            string word = *iter;
            for (auto ch = word.begin(); ch != word.end(); ++ch) {
                char tmp = *ch;
                for (*ch = 'a'; *ch <= 'z'; ++(*ch)) {
                    if (*ch != tmp) {
                        if (word2.count(word)) {
                            beginIsWord1 ? nexts[*iter].push_back(word) : nexts[word].push_back(*iter);
                            reach = true;
                        } else if (!reach && wordList.count(word)) {
                            word3.insert(word);
                            //wordList.erase(word);   // erase here may be dropout some answer
                            beginIsWord1 ? nexts[*iter].push_back(word) : nexts[word].push_back(*iter);
                        }
                    }
                }
                *ch = tmp;
            }
        }
        return reach || findLadders(word2, word3, wordList, nexts, !beginIsWord1);
    }
    void getPath(string beginWord, const string& endWord,
                unordered_map<string, vector<string> >& nexts,
                vector<vector<string> >& paths,
                vector<string>& path) {
        if (beginWord == endWord) {
            paths.push_back(path);
            return;
        }
        for (auto iter = nexts[beginWord].begin(); iter != nexts[beginWord].end(); ++iter) {
            path.push_back(*iter);
            getPath(*iter, endWord, nexts, paths, path);
            path.pop_back();
        }
    }
};

// opt
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        unordered_map<string, vector<string> > nexts;
        vector<vector<string> > paths;
        vector<string> path;
        path.push_back(beginWord);
        unordered_set<string> word1, word2;
        word1.insert(beginWord);
        word2.insert(endWord);
        wordList.erase(beginWord);
        wordList.erase(endWord);
        if (findLadders(word1, word2, wordList, nexts, true))
            getPath(beginWord, endWord, nexts, paths, path);
        return paths;
    }
    bool findLadders(unordered_set<string>& word1,
                    unordered_set<string>& word2,
                    unordered_set<string> &wordList,
                    unordered_map<string, vector<string> >& nexts,
                    bool beginIsWord1) {
        if (word1.empty()) return false;
        if (word1.size() > word2.size())
            return findLadders(word2, word1, wordList, nexts, !beginIsWord1);
        unordered_set<string> word3;
        bool reach = false;
        for (auto iter = word1.begin(); iter != word1.end(); ++iter) {
            string word = *iter;
            for (auto ch = word.begin(); ch != word.end(); ++ch) {
                char tmp = *ch;
                for (*ch = 'a'; *ch <= 'z'; ++(*ch)) {
                    if (*ch != tmp) {
                        if (word2.count(word)) {
                            beginIsWord1 ? nexts[*iter].push_back(word) : nexts[word].push_back(*iter);
                            reach = true;
                        } else if (!reach && wordList.count(word)) {
                            word3.insert(word);
                            beginIsWord1 ? nexts[*iter].push_back(word) : nexts[word].push_back(*iter);
                        }
                    }
                }
                *ch = tmp;
            }
        }
        for (auto iter = word3.begin(); iter != word3.end(); ++iter) wordList.erase(*iter);
        return reach || findLadders(word2, word3, wordList, nexts, !beginIsWord1);
    }
    void getPath(string beginWord, const string& endWord,
                unordered_map<string, vector<string> >& nexts,
                vector<vector<string> >& paths,
                vector<string>& path) {
        if (beginWord == endWord) {
            paths.push_back(path);
            return;
        }
        for (auto iter = nexts[beginWord].begin(); iter != nexts[beginWord].end(); ++iter) {
            path.push_back(*iter);
            getPath(*iter, endWord, nexts, paths, path);
            path.pop_back();
        }
    }
};
