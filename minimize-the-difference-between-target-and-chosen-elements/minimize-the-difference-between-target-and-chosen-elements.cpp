class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int m=mat.size(),n=mat[0].size();
        unordered_set<int> s({0});
        for(int i=0;i<m;++i){
            unordered_set<int> tmp;
            int great=INT_MIN;
            for(auto j:s){
                
                for(auto k:mat[i]){
                    if(k+j<=target) tmp.insert(k+j);
                    else{
                        if(great==INT_MIN||k+j<great)
                            great=k+j;
                    }
                }
                
            }
            if(great!=INT_MIN) tmp.insert(great);
            s=move(tmp);
        }
        int diff=INT_MAX;
        for(auto i:s){
            diff=min(diff,abs(i-target));
        }
        return diff;
    }
};