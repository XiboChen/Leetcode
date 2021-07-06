class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int max_ele=*std::max_element(arr.begin(),arr.end());
        vector<int> v(max_ele+1);
        
        for(int i=0;i<arr.size();i++){
            v[arr[i]]++;
        }
        vector<int> freq;
        for(int i=0;i<v.size();i++){
            if(v[i]) freq.push_back(v[i]);
        }
        sort(freq.begin(),freq.end(),[](const int&a,const int&b){
            return a>b;
        });
        int cnt=0,res=0;
        for(auto i:freq){
            cnt+=i;
            res++;
            if(cnt>=arr.size()/2) break;
        }
        return res;
    }
};