class Solution {
public:
    string frequencySort(string s) {
        string res="";
        unordered_map<char,int> m;
        priority_queue<pair<int,char>> q;
        for(auto c:s) ++m[c];
        for(auto i:m) q.push(make_pair(i.second,i.first));
        while(!q.empty()){
            //auto t=q.top();
            res.append(q.top().first,q.top().second);
            q.pop();
        }
        return res;
        
        
        /*std::sort*/
        // unordered_map<char,int> m;
        // for(auto c:s) ++m[c];
        // //不sort map，直接sort s。
        // //*****  这里因为lamda sort里要引用map的value，所以要在[]里加&才可以调用map。
        // sort(s.begin(),s.end(),[&](char& a,char& b){
        //     return m[a]>m[b] || (m[a]==m[b]&&a<b);
        // });
        // return s;
    }
};