class Solution {
public:
    string simplifyPath(string path) {
        vector<string> vec;
        for (int i = 1; i < path.size(); ) {
            int j = path.find_first_of('/', i);
            if (j == string::npos) j = path.size();
            string tmp = path.substr(i, j - i);
            if (tmp == "..") {
                if (!vec.empty()) vec.pop_back();
            } else if (tmp != "." && i != j) vec.push_back(tmp);
            i = j + 1;
        }
        if (vec.empty()) return "/";
        stringstream ss;
        for (int i = 0; i < vec.size(); ++i)
            ss << '/' << vec[i];
        return ss.str();
    }
};
