class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> res;
        for(int i=0;i<nums.size();++i){
            auto j=m.find(target-nums[i]);
            
            if(j!=m.end() && (i!=j->second)){
                res.push_back(i);
                res.push_back(j->second);
            }
            m[nums[i]]=i;
        }
        return res;
    }
    
};






















// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int,int> m;
//         vector<int> res;
//         for(int i=0;i<nums.size();++i){
//             int diff=target-nums[i];
//             auto it=m.find(diff);
//             if(it!=m.end()&&it->second!=i){
//                 res.push_back(i);
//                 res.push_back(it->second);
//                 return res;
//             }
//             else m[nums[i]]=i;
//         }
//         return {};
//     }
// };

























// class Solution {
// public:
//     vector<int> twoSum(vector<int> nums, int target){
//         vector<int> res;
//         unordered_map<int,int> m;
//         for(int i=0;i<nums.size();i++){
           
//             unordered_map<int,int>::iterator it;
//             it=m.find(target-nums[i]);
            
//             if(it!=m.end()){
//                 if(it->second!=i){
//                     res.push_back(i);
//                     res.push_back(it->second);
//                 }
//             }
            
//                 m.emplace(nums[i],i);
            
//         }
//         return res;
//     }
// };







// // class Solution {
// // public:
// //     vector<int> twoSum(vector<int>& nums, int target) {
// //         map<int,int> nm;
// //         vector<int> result;
// //         for(int i=0;i<nums.size();i++){
// //             nm.emplace(nums[i],i);
// //         }
        
// //         for(int i=0;i<nums.size();i++){
// //             map<int,int>::iterator it;
// //             it=nm.find(target-nums[i]);
// //             if(it!=nm.end()){
// //                 if(i!=it->second){
// //                     result.push_back(i);
// //                     result.push_back(it->second);
// //                     break;
// //                 }
// //             }
// //         }
// //         return result;
// //     }
// // };