class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1;
        int k=m+n-1;
        while(j>=0){
            nums1[k--]=(i>=0&&nums1[i]>nums2[j])?nums1[i--]:nums2[j--];
            //--k;
        }
        
        
        
      // if(n==0){
      //     return;
      // }
      //   else if(m==0){
      //       nums1=nums2;
      //       return;
      //   }
      // int i=m-1;
      // int j=n-1;
      // int counter=m+n-1;
      // while(1){
      //     if(nums1[i]>nums2[j]){
      //         nums1[counter]=nums1[i];
      //         i--;
      //         counter--;
      //     }
      //     else{
      //         nums1[counter]=nums2[j];
      //         j--;
      //         counter--;
      //     }
      //     if(j<0){
      //         break;
      //     }
      //     else if(i<0){
      //         while(j>=0){
      //             nums1[counter]=nums2[j];
      //             j--;
      //             counter--;
      //         }
      //         break;
      //     }
      // }
          
      }
};
    
    
    
    
    
    
    
/*   
vector<int> nums3;
      int i=0;
      int j=0;
      while(1){
          if(i>m-1||j>n-1){
              break;
          }
          if(nums1[i]<nums2[j]){
              nums3.push_back(nums1[i]);
              i++;
          }
          else{
              nums3.push_back(nums2[j]);
              j++;
          }
      }
        if(j<n){
            for(int k=j;k<n;k++){
                nums3.push_back(nums2[k]);
            }
        }
        if(i<m){
            for(int k=i;k<m;k++){
                nums3.push_back(nums1[k]);
            }
        }
      nums1=nums3;
        
    }
*/