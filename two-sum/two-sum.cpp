class Solution {
public:
    vector<int> twoSum(vector<int> nums, int target){
        vector<int> res;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
           
            unordered_map<int,int>::iterator it;
            it=m.find(target-nums[i]);
            
            if(it!=m.end()){
                if(it->second!=i){
                    res.push_back(i);
                    res.push_back(it->second);
                }
            }
            
                m.emplace(nums[i],i);
            
        }
        return res;
    }
};













































// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         map<int,int> nm;
//         vector<int> result;
//         for(int i=0;i<nums.size();i++){
//             nm.emplace(nums[i],i);
//         }
        
//         for(int i=0;i<nums.size();i++){
//             map<int,int>::iterator it;
//             it=nm.find(target-nums[i]);
//             if(it!=nm.end()){
//                 if(i!=it->second){
//                     result.push_back(i);
//                     result.push_back(it->second);
//                     break;
//                 }
//             }
//         }
//         return result;
//     }
// };