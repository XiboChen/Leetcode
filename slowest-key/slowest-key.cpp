class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n=releaseTimes.size();
        vector<int> duration(n,releaseTimes[0]);
        int maxidx=0,maxval=releaseTimes[0];
        for(int i=1;i<releaseTimes.size();i++){
            duration[i]=releaseTimes[i]-releaseTimes[i-1];
            if(maxval<duration[i]){
                maxval=duration[i];
                maxidx=i;
            }
            else if(maxval==duration[i]){
                maxidx=keysPressed[maxidx]>keysPressed[i]?maxidx:i;
            }
        }
        //char res;
        for(int i=0;i<keysPressed.size();i++){
            if(i==maxidx) 
                return keysPressed[i];
                //res=keysPressed[i];
        }
        //return res;
        return ' ';
    }
};