class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> range(ranges.size());
        for(int i=0;i<ranges.size();++i){
            range[i].push_back(max(0,i-ranges[i]));
            range[i].push_back(min(i+ranges[i],n));
        }
        
        sort(range.begin(),range.end(),[](vector<int>& a,vector<int>& b){
            return a[0]<b[0]||(a[0]==b[0]&&a[1]<b[1]);
        });
        
        // for(auto i:range){
        //     for(auto j:i)
        //         cout<<j<<" ";
        //     cout<<endl;
        // }
        
        int res=0,right=0; //初始化答案，最右位置
        int cur=0; //初始化当前区间
        while(cur<=n){
            if(range[cur][0]>right) break; //当前区间最左侧大于最右位置，存在间隙
            //遍历可以覆盖到最右位置的下一个最右
            int r=right;
            while(cur<=n&&range[cur][0]<=right){
                r=max(r,range[cur][1]);
                cur++;
            }
            res++;
            right=r;
            if(right==n) break;
        }
        
        return right==n?res:-1;
/*
n个土地数量，n+1个水龙头。
定义一个land表示在所有能够覆盖这块土地的水龙头中，能覆盖最右边位置的水龙头。记录它最右边的土地

index=0，表示能覆盖0-1土地的所有水龙头能到达的最右边，值为5（水龙头1也能覆盖0-1，是最远的5）
值为5，代表能覆盖到最右边的4-5.
所以index是右边的土地，值是水龙头左边的土地

land[i]：index表示每块土地，index=0，即土地0-1，水龙头为0；index=1，即土地1-2，水龙头为1
*/
    }
};