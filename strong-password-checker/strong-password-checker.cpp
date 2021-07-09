class Solution {
public:
    int strongPasswordChecker(string password) {
        int res=0,n=password.size(),lower=1,upper=1,digit=1;
        vector<int> v(n,0);
        for(int i=0;i<n;){
            if(password[i]>='a'&&password[i]<='z') lower=0;
            if(password[i]>='A'&&password[i]<='Z') upper=0;
            if(password[i]>='0'&&password[i]<='9') digit=0;
            int j=i;
            while(i<n&&password[i]==password[j]){
                i++;
            }
            v[j]=i-j;
        }
        int missing=(lower+upper+digit); //条件2差几个
        if(n<6){
            int diff=6-n;   //差几个满足size
            res+=missing+max(0,diff-missing);
        }else{
            int over=max(n-20,0),left=0;
            res+=over;
            for(int k=1;k<3;k++){
                for(int i=0;i<n&&over>0;i++){
                    if(v[i]<3 || v[i]%3!=(k-1)) continue; //余数是1，0的直接删除k个
                    v[i]-=min(over,k);
                    over-=k;
                }
            }
            for(int i=0;i<n;i++){
                if(v[i]>=3 && over>0){
                    int need=v[i]-2;
                    v[i]-=over;
                    over-=need;   //删，不知道为啥，但是这步之后，总数就是20了
                }
                if(v[i]>=3) left+=v[i]/3; //改
            }
            res+=max(missing,left);
        }
        return res;
    }
    /*
    条件：1.size 6-20
          2.至少一大写，一小写，一数字
          3.不能有连续三个相同
    问题：1.长度小于6，长度大于20，插入删除
          2.缺失字符或数字，插入或替换
          3.重复字符，都可
    1.size<6 重复字符个数范围[3,5]，问题1，2可替代3.
    2.size>=6 尽量不插入
    
    步骤：
    1.算出超过20个的个数over，把over加到结果res中，因为无论如何这over个删除操作都是要做的。
      没超过，over就是0。
    2.用变量left表示解决重复字符最少需要替换的个数，初始化为0。
    3.然后 遍历之前统计字符出现个数，如果某个字符出现个数>=3 && over大于0，
      将个数减为最近的3m+2个，over也对应的减少，一旦over小于等于0，不要再进行删除操作。
    4.如果所有重复个数都减为3m+2了，但是over仍大于0，那么我们还要进一步的进行删除操作，这回每次直接删除3m个，直到over小于等于0为止，剩下的如果还有重复个数大于3的字符，我们算出置换字符需要的个数直接加到left中即可，最后我们比较left和missing，取其中较大值加入结果res中即可，参见代码如下：
    */
};
