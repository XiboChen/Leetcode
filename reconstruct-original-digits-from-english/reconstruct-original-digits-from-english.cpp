class Solution {
public:
    string originalDigits(string s) {
        string res="";
        vector<int> count(128,0),nums(10,0);
        for(auto i:s) count[i]++;
        nums[0]=count['z'];
        nums[2]=count['w'];
        nums[4]=count['u'];
        nums[6]=count['x'];
        nums[8]=count['g'];
        nums[1]=count['o']-nums[0]-nums[2]-nums[4];
        nums[3]=count['h']-nums[8];
        nums[5]=count['f']-nums[4];
        nums[7]=count['s']-nums[6];
        nums[9]=count['i']-nums[6]-nums[8]-nums[5];
      
        for(int i=0;i<nums.size();++i){
            for(int j=0;j<nums[i];++j){
                res+=(i+'0');
            }
        }
        return res;
    }
};