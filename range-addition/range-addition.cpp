class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> arr(length+1,0);
        for(auto update:updates){
            arr[update[0]]+=update[2];
            arr[update[1]+1]-=update[2];
        }
        int sum=0;
        for(int i=1;i<arr.size();++i){
            arr[i]+=arr[i-1];
        }
        arr.pop_back();
        return arr;
        /*
        累加和数组：在[start,n)每个都+2，在[end+1,n)每个都-2，所以只需要更改start位置+2，累加和自然会对后面每个都+2，
        在end+1处-2，对后面每个都-2
        */
    }
};