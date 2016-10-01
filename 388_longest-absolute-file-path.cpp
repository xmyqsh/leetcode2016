class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> path;
        auto pos = input.find_first_of('\n', 0);
        pos = pos == string::npos ? input.size() : pos;
        path.push_back(pos);
        int len = input.substr(0, pos).find_first_of('.') == string::npos ? 0 : pos;
        travel(path, input, pos + 1, len);
        return len;
    }
    void travel(vector<int>& path, string input, int begin, int& len) {
        if (begin >= input.size()) return;
        int pos = begin, count = 1;
        for (; input[pos] == '\t'; pos += 1, ++count);
        vector<int> newPath(path);
        while (newPath.size() >= count) newPath.pop_back();
        pos = input.find_first_of('\n', (begin = pos));
        pos = pos == string::npos ? input.size() : pos;
        newPath.push_back(pos - begin);
        int newLen = newPath.size() - 1;
        for (auto l : newPath) newLen += l;
        newLen = input.substr(begin, pos - begin).find_first_of('.') == string::npos ? 0 : newLen;
        swap(path, newPath);
        len = max(newLen, len);
        travel(path, input, pos + 1, len);
    }
};
