class Solution {
public:
    int lengthOfLastWord(string s) {
        int res=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                //如果不是第一个(因为第一个没法访问前一个),且前一个是空格，就是新的单词
                if(i!=0 && s[i-1]==' ') 
                    res=1;
                else res++;
            }
        }
        return res;
    }
};