class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res=INT_MAX,n=nums.size();
        for(int i=0;i<n;i++){
            int tmp=0;
            for(int j=i;j<n;j++){
                //cout<<i<<" "<<j<<endl;
                if(i!=j)
                    tmp+=nums[j];
                else tmp=nums[i];
                //cout<<"tmp: "<<tmp<<endl;
                if(tmp>=target){
                    res=min(res,j-i+1);
                    //cout<<"res: "<<res<<endl;
                    break;
                }
              if(i==0&&j==n-1&&tmp<target)
                return 0;
            }
            
            //cout<<"------"<<endl;
        }
        return res;
    }
};