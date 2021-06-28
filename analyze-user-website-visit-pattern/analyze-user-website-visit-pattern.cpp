class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string,vector<pair<int,string>>> m;//用户名,<用户访问时间,网站>
        int n=username.size();
        //(1)
        for(int i=0;i<n;++i){
            m[username[i]].push_back({timestamp[i],website[i]});
        }
        for(auto it=m.begin();it!=m.end();++it){
            sort(it->second.begin(),it->second.end(),[&](auto a,auto b){
                return a.first<b.first;});
        }
        //(2)
        vector<string> path; //存所有满足三个长度的路径
        // map<vector<string>,unordered_set<string>> count;//同一路径用过的用户有哪些
                                                    //（这里用set存用户名为了不重复）
        for(auto it=m.begin();it!=m.end();++it){
            dfs(it->second,path,0,it->first); //回溯生成所有的三元组 
        }
        
        //(3)
        int maxcount=0;
        vector<vector<string>> res;
        for(auto it=count.begin();it!=count.end();it++){
            //选出人数最多的路径
            if(it->second.size()>maxcount){
                res.clear();
                res.push_back(it->first);
                maxcount=it->second.size();
            }else if(it->second.size()==maxcount)
                res.push_back(it->first);
        }
        sort(res.begin(),res.end()); //取字典顺序最小的
        return res[0];
    }
    
    void dfs(vector<pair<int,string>>& web,vector<string>& path,int idx,string username){
        //(2)1
        if(path.size()==3){
            count[path].insert(username);
            return;
        }
        for(int i=idx;i<web.size();i++){
            path.push_back(web[i].second);
            dfs(web,path,i+1,username);
            path.pop_back(); //每一遍return回来，最后path被清空了
        }
    }
private:
    map<vector<string>,unordered_set<string>> count;
};

/*
(1)
m: key:        joe          |      james         |       mary
 value: <1,home>,<2,about>, | <4,home>,<5,cart>, | <8,home>,<9,about>
            <3,career>      | <6,maps>,<7,home>  |    <10,career>
            
(2)1: path:<home,about,career>
(2)2: count:
      key: <home,about,career> ...
    value:   joe                ...
*/