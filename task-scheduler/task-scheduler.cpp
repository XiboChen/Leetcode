class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26,0);
        for(auto task:tasks){ //找到最大出现频率的任务
            cnt[task-'A']++;
        }
        sort(cnt.begin(),cnt.end()); //sort后，最后面的就是最大的
        int i=25,mx=cnt[25],size=tasks.size();
        while(i>=0 && cnt[i]==mx){
            i--;
        }
        return max(size,(mx-1)*(n+1)+25-i);
    }
};