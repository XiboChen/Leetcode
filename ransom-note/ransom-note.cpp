class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> m;
        for(auto i:magazine){
            m[i]++;
        }
        for(auto i:ransomNote){
            m[i]--;
            if(m[i]<0) return false;
            
        }
        return true;
    }
};