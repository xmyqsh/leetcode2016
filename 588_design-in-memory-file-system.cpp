class FileSystem {
public:
    FileSystem() {
        root = new Dir;
    }
    
    vector<string> ls(string path) {
        Entry* cur = root;
        string name;
        for (size_t i = 1, j; i < path.size(); i = j + 1) {
            j = path.find('/', i);
            if (j == string::npos) j = path.size();
            name = path.substr(i, j - i);
            cur = dynamic_cast<Dir*>(cur)->se[name];
        }
        if (dynamic_cast<File*>(cur))
            return {name};
        vector<string> result;
        for (auto& item : dynamic_cast<Dir*>(cur)->se)
            result.push_back(item.first);
        return result;
    }
    
    void mkdir(string path) {
        Entry* cur = root;
        for (size_t i = 1, j; i < path.size(); i = j + 1) {
            j = path.find('/', i);
            if (j == string::npos) j = path.size();
            string name = path.substr(i, j - i);
            if (!dynamic_cast<Dir*>(cur)->se.count(name))
                dynamic_cast<Dir*>(cur)->se[name] = new Dir;
            cur = dynamic_cast<Dir*>(cur)->se[name];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        Entry* cur = root;
        for (size_t i = 1, j; i < filePath.size(); i = j + 1) {
            bool file = false;
            j = filePath.find('/', i);
            if (j == string::npos) {
                file = true;
                j = filePath.size();
            }
            string name = filePath.substr(i, j - i);
            if (!dynamic_cast<Dir*>(cur)->se.count(name))
                dynamic_cast<Dir*>(cur)->se[name] = file ? (Entry*)(new File) : (Entry*)(new Dir);
            cur = dynamic_cast<Dir*>(cur)->se[name];
        }
        dynamic_cast<File*>(cur)->content += content;
    }
    
    string readContentFromFile(string filePath) {
        Entry* cur = root;
        for (size_t i = 1, j; i < filePath.size(); i = j + 1) {
            j = filePath.find('/', i);
            if (j == string::npos) j = filePath.size();
            string name = filePath.substr(i, j - i);
            cur = dynamic_cast<Dir*>(cur)->se[name];
        }
        return dynamic_cast<File*>(cur)->content;
    }
private:
    struct Entry {
        virtual ~Entry() {}
    };
    struct Dir : Entry {
        map<string, Entry*> se;
    };
    struct File : Entry {
        string content;
    };
private:
    Entry* root;
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * vector<string> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * string param_4 = obj.readContentFromFile(filePath);
 */
