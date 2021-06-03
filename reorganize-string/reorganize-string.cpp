class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26,0);
        int maxCount=0,n=s.size();
        string res="";
        for(auto c:s){
            count[c-'a']++;
            maxCount=max(maxCount,count[c-'a']);
        }
        if(maxCount>(n+1)/2)
            return "";
        priority_queue<pair<int,char>> q;
        for(int i=0;i<count.size();i++){
            if(count[i]>0)
                q.push({count[i],i+'a'});
        }
        while(q.size()>=2){
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