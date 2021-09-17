class Solution {
public:
    int romanToInt(string s) {
        int res=0;
        // unordered_map<char,int> m{{I,1},{V,5},{X,10},{L,50},{C,100},{D,500},{M,1000}};
        for(int i=0;i<s.size();++i){
            
            if(s[i]=='I'){
                if(s[i+1]=='V'){
                    res+=4;
                    ++i;
                    continue;
                }
                if(s[i+1]=='X'){
                    res+=9;
                    ++i;
                    continue;
                }
                ++res;
            }
            if(s[i]=='X'){
                if(s[i+1]=='L'){
                    res+=40;
                    ++i;
                    continue;
                }
                if(s[i+1]=='C'){
                    res+=90;
                    ++i;
                    continue;
                }
                res+=10;
            }
            if(s[i]=='C'){
                if(s[i+1]=='D'){
                    res+=400;
                    ++i;
                    continue;
                }
                if(s[i+1]=='M'){
                    res+=900;
                    ++i;
                    continue;
                }
                res+=100;
            }
            if(s[i]=='V') res+=5;
            if(s[i]=='L') res+=50;
             if(s[i]=='D') res+=500;
             if(s[i]=='M') res+=1000;
            
           
        }
        return res;
    }
};