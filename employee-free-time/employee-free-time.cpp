/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> res,v;
        for(auto i:schedule){
            v.insert(v.end(),i.begin(),i.end());
        }
        
        sort(v.begin(),v.end(),[](Interval& a,Interval&b){
            return a.start<b.start || (a.start==b.start&&a.end<b.end);
        });
        
        Interval t=v[0];
        for(auto i:v){
            if(t.end<i.start){
                res.push_back(Interval(t.end,i.start));
                t=i;
            }
            else t=t.end<i.end?i:t;
        }
        // for(auto i:v){
        //     cout<<i.start<<" "<<i.end<<endl;
        // }
        return res;
    }
};