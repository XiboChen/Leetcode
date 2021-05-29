class TweetCounts {
public:
    TweetCounts() {
      
    }
    
    void recordTweet(string tweetName, int time) {
        m[tweetName].push_back(time);
        
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int delta=60;
        if(freq=="hour") delta=60*60;
        else if(freq=="day") delta=60*60*24;
        int intervals=(endTime-startTime)/delta+1;//比如统计第1秒到68秒的鸣叫声，要求以分钟做间隔，也就是1到60秒，60秒到68秒，每个时间间隔的鸣叫数
        vector<int> res(intervals);
        for(int i=0;i<m[tweetName].size();i++){
            if(m[tweetName][i]<startTime || m[tweetName][i]>endTime) 
                continue;
            res[(m[tweetName][i]-startTime)/delta]++;
        }
        return res;
        
    }
private:
    unordered_map<string,vector<int>> m;
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */