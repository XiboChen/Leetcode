class FileSystem {
public:
    FileSystem() {
        dirs["/"];
    }
    
    vector<string> ls(string path) {
        if(files.count(path)){
            auto pos=path.find_last_of('/');
            return {path.substr(pos+1)};
        }
        auto t=dirs[path];
        return vector<string>(t.begin(),t.end());
    }
    
    void mkdir(string path) {
        istringstream in(path);
        string t="",dir="";
        while(getline(in,t,'/')){
            if(t.empty()) continue;
            if(dir.empty()) dir+='/';
            dirs[dir].insert(t);
            if(dir.size()>1) dir+='/';
            dir+=t;
        }
    }
    
    void addContentToFile(string filePath, string content) {
        int pos=filePath.find_last_of('/');
        string dir=filePath.substr(0,pos);
        string file=filePath.substr(pos+1);
        if(dir.empty()) dir="/";
        if(!dirs.count(dir)) mkdir(dir);
        files[filePath].append(content);
        dirs[dir].insert(file);
    }
    
    string readContentFromFile(string filePath) {
        return files[filePath];
    }
    unordered_map<string,set<string>> dirs;
    unordered_map<string,string> files;
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */