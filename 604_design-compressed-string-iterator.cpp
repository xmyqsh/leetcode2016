class StringIterator {
public:
    StringIterator(string compressedString) {
        this->compressedString = compressedString;
        this->cnt = 0;
    }
    
    char next() {
        if (!hasNext()) return ' ';
        if (cnt) {
            --cnt;
            return cur;
        }
        cur = compressedString[0];
        int i = 1, num = 0;
        while (isdigit(compressedString[i])) {
            num = num * 10 + compressedString[i] - '0';
            ++i;
        }
        compressedString = compressedString.substr(i);
        cnt = num - 1;
        return cur;
    }
    
    bool hasNext() {
        return cnt || !compressedString.empty();
    }
private:
    string compressedString;
    char cur;
    int cnt;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */
