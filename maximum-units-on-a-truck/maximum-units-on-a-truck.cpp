class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int res=0,i=0;
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int>& a,vector<int>& b){
            return a[1]>b[1];
        });
        while(truckSize>0&&i<boxTypes.size()){
            res+=min(boxTypes[i][0],truckSize)*boxTypes[i][1];
            truckSize-=boxTypes[i][0];
            ++i;
        }
        return res;
    }
};