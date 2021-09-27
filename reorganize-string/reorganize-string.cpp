class Solution {
public:
    string reorganizeString(string s) {
        vector<int> cnt(26,0);
        int max_=0;
        for(auto i:s){
            ++cnt[i-'a'];
            max_=max(max_,cnt[i-'a']);
        }
        if(max_>(s.size()+1)/2) return "";
        
        priority_queue<pair<int,char>> q;
        for(int i=0;i<cnt.size();++i){
            if(cnt[i]>0)
                q.push({cnt[i],i+'a'});
        }
        string res="";
        while(q.size()>1){
            auto t1=q.top();q.pop();
            auto t2=q.top();q.pop();
            res+=t1.second;
            res+=t2.second;
            if(--t1.first>0) q.push(t1);
            if(--t2.first>0) q.push(t2);
        }
        if(q.size()>0) res+=q.top().second;
        return res;
    }
};