class Solution {
public:
    bool confusingNumber(int n) {
        vector<int> v{0,1,-1,-1,-1,-1,9,-1,8,6};
        string str=to_string(n);
        bool res=false;
        int N=str.size(),left=0,right=N-1;
        while(left<=right){
            if(v[str[left]-'0']==-1||v[str[right]-'0']==-1) return false;
            if(v[str[left]-'0']!=(str[right]-'0')) res=true; 
            ++left;--right;
        }
        return res;
        
        // int num=0,oldnum=n;
        // unordered_set<int> s{{2,3,4,5,7}};
        // while(n>0){
        //     int digit=n%10;
        //     if(s.count(digit)) return false;
        //     if(digit==6) digit=9;
        //     else if(digit==9) digit=6;
        //     num=num*10+digit;
        //     num/=10;
        // }
        // return num!=oldnum;
    }
};