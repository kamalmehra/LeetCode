/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> D = binaryMatrix.dimensions();
        int n  = D[0] , m = D[1];
        int start_x =  0 , start_y =  m-1;
        
        int best = INT_MAX;
        while(start_x < n && start_y >=0){
            if(binaryMatrix.get(start_x , start_y)){
                best = start_y;
                start_y--;
            }
            else {
                start_x++;
            }
        }
        if(best==INT_MAX) best=-1;
        return best;
    }
};