class Solution {
public:
    int findContentChildren(vector<int>& children, vector<int>& cookies) {
        sort(children.begin(),children.end());
        sort(cookies.begin(),cookies.end());
        int child=0,cookie=0;
        while(child<children.size()&&cookie<cookies.size()){
            if(cookies[cookie]>=children[child]) 
                child++;
            cookie++;
        }
        return child;
    }
};