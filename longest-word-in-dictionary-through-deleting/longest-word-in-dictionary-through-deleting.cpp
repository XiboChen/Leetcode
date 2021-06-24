class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        /*1.使用sort，这样第一个就是最长最小的那个*/
        // sort(dictionary.begin(),dictionary.end(),[](string& a, string& b){
        //     if(a.size()==b.size()) return a<b;
        //     return a.size()>b.size();
        // });
        
        /*2.不使用sort，更新res*/
        string res="";
        for(auto str:dictionary){
            int i=0;
            for(auto c:s){
                if(i<str.size()&&c==str[i]) i++;
            }
            //if(i==str.size()) return str;
            if(i==str.size()&&str.size()>=res.size()){
                if(str.size()>res.size() || str<res)
                    res=str;
            }
        }
        //return "";
        return res;
    }
};