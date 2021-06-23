class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        unordered_map<char,int> m;
        int start=0,end=0;
        for(int i=0;i<s.size();i++)
            m[s[i]]=i;
        for(int i=0;i<s.size();i++){
            end=max(end,m[s[i]]);
            if(i==end){
                res.push_back(end-start+1);
                start=i+1;
            }
        }
        return res;
    }
}; 
//在map里存入每个字母对应的起始位置，结束位置，这里可以只存入结束位置，再遍历一遍s，找到每个字母最后出现的位置，当i等于最后位置，就可以直接存了，相当于存起始了