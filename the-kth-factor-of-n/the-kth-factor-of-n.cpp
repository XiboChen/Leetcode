class Solution {
public:
    int kthFactor(int n, int k) {
        set<int> s;
        for(int i=1;i<=n;++i){
            if(n%i==0){
                s.insert(i);
                s.insert(n/i);
            }
        }
        if(s.size()<k) return -1;
        set<int>::iterator it = s.begin();
        advance(it, k-1);
        int x = *it;
        return x;
    }
};