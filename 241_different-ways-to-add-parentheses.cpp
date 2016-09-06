class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string, vector<int> > cache;
        return diffWaysToCompute(input, cache);
    }
    vector<int> diffWaysToCompute(const string& input, unordered_map<string, vector<int> >& cache) {
        vector<int> result;
        for (int i = 0; i < input.size(); ++i) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> result1, result2;
                string former = input.substr(0, i), latter = input.substr(i + 1);
                auto pos1 = cache.find(former);
                auto pos2 = cache.find(latter);
                if (pos1 == cache.end()) {
                    result1 = diffWaysToCompute(former);
                    cache[former] = result1;
                } else result1 = cache[former];
                if (pos2 == cache.end()) {
                    result2 = diffWaysToCompute(latter);
                    cache[latter] = result2;
                } else result2 = cache[latter];
            
                for (auto r1 : result1)
                    for (auto r2 : result2)
                        if (input[i] == '+') result.push_back(r1 + r2);
                        else if (input[i] == '-') result.push_back(r1 - r2);
                        else result.push_back(r1 * r2);
            }
        }
        if (result.empty()) result.push_back(stoi(input));
        return result;
    }
};
