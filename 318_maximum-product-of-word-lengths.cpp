class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> bits(words.size(), 0);
        for (int i = 0; i != words.size(); ++i)
            for (auto c : words[i])
                bits[i] |= 1 << (c - 'a');
        int result = 0;
        for (int i = 0; i != bits.size(); ++i)
            for (int j = i + 1; j < bits.size(); ++j)
                if (!(bits[i] & bits[j]))
                    result = max(result, (int)words[i].size() * (int)words[j].size());
        return result;
    }
};
