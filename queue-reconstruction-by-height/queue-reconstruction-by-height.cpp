class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        sort(people.begin(),people.end(),[](vector<int>& a,vector<int>& b){
            return a[0]>b[0] || (a[0]==b[0]&&a[1]<b[1]);
        });
            for(auto a:people){
                res.insert(res.begin()+a[1],a);
            }
        return res;
    }
};