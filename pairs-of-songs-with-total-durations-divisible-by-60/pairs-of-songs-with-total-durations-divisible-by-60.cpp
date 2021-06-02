class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res=0;
        unordered_map<int,int> m;
        unordered_set<int> s;
        for(auto t:time){
            // while(t>60){
            //     t=t%60;
            // }
            m[t%60]++;
        }
        for(auto a:m){
            if(s.count(a.first))
                continue;
            if(a.first%60==0 || a.first==30){
                res+=(a.second-1)*a.second/2;
            }
            else{
                int target=60-a.first;
                if(!m.count(target)) continue;
                res+=a.second*m[target];
                s.insert(target);
            }
        }
        return res;
    }
};