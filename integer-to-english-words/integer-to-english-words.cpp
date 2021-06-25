class Solution {
public:
    string numberToWords(int num) {
        string res=convertHundred(num%1000);
        vector<string> v={"Thousand","Million","Billion"};
        for(int i=0;i<3;i++){  //这里之所以是循环4次，是因为最高只能到billion,3个一组只                                               需要处理四组即可。
            num/=1000;
            res=num%1000? convertHundred(num%1000)+" "+v[i]+" "+res:res;
        }
        while(res.back()==' ') res.pop_back();
        return res.empty()?"Zero":res;
    }
    
    string convertHundred(int num){
        vector<string> v1={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        vector<string> v2={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        string res;
        int a=num/100,b=num%100,c=num%10; //123->1;23;3
        res=b<20?v1[b]:v2[b/10]+(c?" "+v1[c]:""); //这里b/10对应了上面vector里前面多加                                                      了几个"",为了正好对应上index。
        if(a>0) res=v1[a]+ " Hundred"+(b?" "+res :"");
        return res;
    }
};