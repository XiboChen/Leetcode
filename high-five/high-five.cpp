class Solution {
public:
    static bool cmp(int& a,int& b){
        return a>b;
    }
    
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int,vector<int>> m;
        vector<vector<int>> res;
        for(auto i:items){
            m[i[0]].push_back(i[1]);
        }
        
        
        
        for(auto it=m.begin();it!=m.end();it++){
            //it n=it->second.size();
            int sum=0;
            int n=it->second.size();
            if(n>5){
                sort(it->second.begin(),it->second.end(),cmp);
            }
            
            for(auto it=m.begin();it!=m.end();it++){
            cout<<"m[0]: "<<it->first<<" m[1]: ";
            for(auto i:it->second){
                cout<<i<<" ";
            }
            cout<<endl;
        }
            
            for(int i=0;i<5;i++){
                sum+=it->second[i];
            }
            cout<<"sum: "<<sum<<endl;
            cout<<"size: "<<it->second.size()<<endl;
            res.push_back({it->first,(int)(sum/5)});
        }
        return res;
    }
};











// static bool cmp(vector<int>& a,vector<int>& b){
//         if(a[0]==b[0]) return a[1]>b[1];
//         else return a[0]<b[0];
//     }
//      vector<vector<int>> highFive(vector<vector<int>>& items) {
//         vector<vector<int>> ans;
//         sort(items.begin(),items.end(),cmp);
//         int res=items[0][1];
//         for(int i=1,j=0;i<items.size();i++){
//             if(items[i][0]==items[i-1][0]){
//                 (j<5){
//                     res+=items[i][1];
//                     j++;
//                 }
//                 ans.push_back({items[i][0],res});
//             }
//             else{
//                 res=items[i][1];
//             }
//         }
        
//         // for(auto i:items){
//         //     for(auto j:i)
//         //         cout<<j<<",";
//         //     cout<<endl;
//         // }
//         return ans;
//    