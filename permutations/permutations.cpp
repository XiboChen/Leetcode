class Solution {
public:
//     void permutation(vector<int>& nums,vector<vector<int>>& res,vector<int>& out,vector<int>& visited,int level){
//         if(level==nums.size()){
//             res.push_back(out);
//             return;
//         }        
//         for(int i=0;i<nums.size();i++){
//             if(visited[i]==1)
//                 continue;
//             visited[i]=1;
//             out.push_back(nums[i]);
//             permutation(nums,res,out,visited,level+1);
//             out.pop_back();
//             visited[i]=0;
//         }
//     }
    
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> res;
//         vector<int> out;
//         vector<int> visited(nums.size(),0);
//         permutation(nums,res,out,visited,0);
//         return res;
//     }
    
    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>> res;
        backtracing(nums,0,res);
        return res;
    }
    
    void backtracing(vector<int>&nums,int level,vector<vector<int>>& res){
        if(level==nums.size()-1){
            res.push_back(nums);
            return;
        }
        for(int i=level;i<nums.size();i++){
            if(i!=level)
                swap(nums[i],nums[level]);
            backtracing(nums,level+1,res);
            if(i!=level)
                swap(nums[i],nums[level]);
        }
    }
};

