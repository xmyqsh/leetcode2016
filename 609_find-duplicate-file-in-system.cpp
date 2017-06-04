class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string> > mp;
        for (auto& str : paths) process(mp, str);
        vector<vector<string> > result;
        for (auto& elem : mp)
            if (elem.second.size() > 1)
                result.push_back(elem.second);
        return result;
    }
    void process(unordered_map<string, vector<string> >& mp, const string& str) {
        int b = 0, e = str.find_first_of(' ', 0);
        string path = str.substr(b, e - b) + "/";
        for (b = e + 1; e != str.size(); b = e + 1) {
            e = str.find_first_of(' ', b);
            if (e == string::npos) e = str.size();
            string fileContent = str.substr(b, e - b);
            int pos = fileContent.find_first_of('(', 0);
            mp[fileContent.substr(pos + 1, fileContent.size() - 1 - pos - 1)].push_back(path + fileContent.substr(0, pos));
        }
    }
};
