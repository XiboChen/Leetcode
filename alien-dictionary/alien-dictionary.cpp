class Solution {
public:
    string alienOrder(vector<string>& words) {
        //之前course schedule用vectorvector表示图，这里因为出现的不是数字，而是字母，
        //并且字母不是26个全出现，所以用map记录一样
        unordered_map<char,vector<char>> graph;
        unordered_map<char,int> indegrees;
        for(auto word:words){  //一定要初始化，不然不能用indegrees[**]
            for(auto c:word){
                indegrees[c]=0;    
            }
        }
        for(int i=0;i<words.size()-1;i++){
            string w1=words[i],w2=words[i+1];
            if(w1.size()>w2.size() && w1.find(w2)==0) return "";
            for(int j=0;j<min(w1.size(),w2.size());j++){  //挨个比
                char c1=w1[j],c2=w2[j];
                if(c1!=c2){
                    graph[c1].push_back(c2);
                    indegrees[c2]++;
                    break;
                }
            }
        }
        queue<char> q;
        for(auto i:indegrees){
            if(i.second==0) q.push(i.first); //push入度为0的
        }
        string res="";
        while(!q.empty()){
            char t=q.front();q.pop();
            res+=t;
            for(auto nei:graph[t]){
                --indegrees[nei];
                if(indegrees[nei]==0){
                    q.push(nei);
                }
            }
        }
        for(auto it:indegrees){   //如果入度都为0，则无环，否则有环
            if(it.second!=0) return "";
        }
        return res;
    }
    
    /*
    wrt/wrf -> t<f
    wrt/er  -> w<e
    er/ett  -> r<t
    ett/rftt-> e<r
    */
        /* print key and value in a map
        // for(auto it=graph.begin();it!=graph.end();it++){
        //     cout<<(*it).first<<" ";
        //     for(auto i:(*it).second)
        //         cout<<i<<" ";
        //     cout<<endl;
        // }
        // for (const auto& p : graph ) {
        //     std::cout << p.first <<" ";
        //         for(auto i:p.second)
        //         cout<<i<<" ";
        //     cout<<endl;
        // }
        */
};