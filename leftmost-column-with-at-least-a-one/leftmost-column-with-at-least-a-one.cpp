/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int rows=binaryMatrix.dimensions()[0];
        int cols=binaryMatrix.dimensions()[1];
        int smallestIdx=cols;
        for(int row=0;row<rows;row++){
            int lo=0,hi=cols-1;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(binaryMatrix.get(row,mid)==1){
                    smallestIdx=min(smallestIdx,mid);
                    hi=mid-1;
                }
                else lo=mid+1;
            }
        }
        return smallestIdx==cols?-1:smallestIdx;
    }
};