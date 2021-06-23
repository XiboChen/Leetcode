class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i=0;i<flowerbed.size();i++){
            if(n==0) return true;
            if(flowerbed[i]==0){
                int pre=(i==0?0:flowerbed[i-1]);
                int next=(i==flowerbed.size()-1?0:flowerbed[i+1]);
                if(pre==0 && next==0){
                    flowerbed[i]=1;
                    n--;
                }
            }
        }
        return n<=0;
    }
};
//思路：只要pre和next都为0，就可以放，修改flowerbed，n--，看最后是不是0