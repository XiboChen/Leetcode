class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> s(arr.begin(),arr.end());  //不用sort，直接有序了，nlogn
        unordered_map<int,int> m;
        int cnt=1;
        for(auto i:s){
            m[i]=cnt++;
        }
        vector<int> res(arr.size());
        for(int i=0;i<arr.size();++i){
            res[i]=m[arr[i]];
        }
        return res;
    }
};