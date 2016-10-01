/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        NestedInteger result, tmp;
        if (s[0] != '[') {
            result.setInteger(stoi(s));
            return result;
        } else if (s.size() == 2) return result;
        int b = 1, e;
        while (b < s.size() && s[b] != ']') {
            e = nextPos(s, b);
            result.add(deserialize(s.substr(b, e - b)));
            b = e + 1;
        }
        return result;
    }
    int nextPos(const string& s, int b) {
        int e = b + 1;
        if (s[b] == '[') {
            int cnt = 1;
            do {
                if (s[e] == '[') ++cnt;
                else if (s[e] == ']') --cnt;
                ++e;
            } while (cnt != 0);
        } else {
            e = s.find_first_of(',', b);
            e = e == string::npos ? s.find_first_of(']', b) : e;
        }
        return e;
    }
};
