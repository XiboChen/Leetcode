class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int res=1,last=0,n=points.size();
        for(int i=1;i<n;i++){
            if(points[i][0]<=points[last][1]){
                if(points[i][1]<points[last][1])
                    last=i;
            }
            else {res++;last=i;}
            cout<<"i: "<<i<<" "<<res<<endl;
        }
        return res;
    }
};