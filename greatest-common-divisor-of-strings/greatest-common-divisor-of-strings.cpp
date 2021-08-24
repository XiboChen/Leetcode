class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int m=str1.size(),n=str2.size();
        string res;
        for(int i=0;i<m;++i){
            string pre=str1.substr(0,i+1),target1,target2;
            for(int j=0;j<m/(i+1);++j){
                target1+=pre;
            }
            if(target1!=str1) continue;
            for(int j=0;j<n/(i+1);++j){
                target2+=pre;
            }
            if(target2!=str2) continue;
            res=pre;
        }
        return res;
    }
};