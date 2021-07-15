class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        //O(nlogd)
        sort(events.begin(),events.end(),[](vector<int>&a,vector<int>&b){
           return a[1]<b[1]; 
        });
        int min_d=INT_MAX;
        int max_d=INT_MIN;
        for(auto e:events){
            min_d=min(min_d,e[0]);
            max_d=max(max_d,e[1]);
        }
        vector<int> days(max_d-min_d+1);        //找到最大最小就可以知道一共有几天可用
        iota(days.begin(),days.end(),min_d);   //days：1 2 3 4 可用
        set<int> s(begin(days),end(days));   //O(n)  //用set方便后面删除，并且不可以重复
        
        int res=0;
        for(auto e:events){
            auto it=s.lower_bound(e[0]);     
            if(it==s.end()||*it>e[1]) continue; 
            //用过的day删除，如果有没用过的，且没超过e{1}，代表可用，继续删除
            s.erase(it);
            res++;
        }
        return res;
        
        // //O(sum(endTime-starttime)) 超时
        // sort(events.begin(),events.end(),[](vector<int>&a,vector<int>&b){
        //    return a[1]<b[1]; 
        // });
        // int res=0;
        // int seen[100001]={0};
        // for(auto event:events){
        //     for(int i=event[0];i<=event[1];++i){
        //         if(seen[i]==1) continue;
        //         ++seen[i];
        //         ++res;
        //         break;
        //     }
        // }
        // return res;
    }
};