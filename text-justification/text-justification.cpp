class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i=0;
        while(i<words.size()){
            int j=i,len=0;
            while(j<words.size() && len+words[j].size()+j-i<=maxWidth){
                len+=words[j++].size();
            }
            int space=maxWidth-len;
            string s;
            for(int k=i;k<j;++k){
                s+=words[k];
                if(space>0){
                    int tmp=0;
                    if(j==words.size()){
                        if(j-k==1) tmp=space;
                        else tmp=1;
                    }else{
                        if(j-k-1>0){
                            if(space%(j-k-1)==0)    
                                tmp=space/(j-k-1);
                            else
                                tmp=space/(j-k-1)+1;
                        }else 
                            tmp=space;
                    }
                    s.append(tmp,' ');
                    space-=tmp;
                }
            }
            res.push_back(s);
            i=j;
        }
        return res;
    }
};