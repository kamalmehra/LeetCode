Interval List Intersections
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int m = B.size();
        int i = 0;
        int j = 0;
        vector<vector<int>> ans;
        
        //[[5,10],[13,23],[24,25]]
        //[[3,5],[8,12],[15,24],[25,26]]
        while(i<n and j<m){
            //A - [0,5]
            //B - [1,3][0,3][1,7][5,9][7,9]
            if(A[i][0] <= B[j][0]){
                if(A[i][1] < B[j][0]){
                    i++;
                }
                else{ // A[i][1]>=B[j][0] something will be common
                    //A - [0,5]
                    //B - [1,3][0,3][1,5][5,5]
                    if(B[j][1]<=A[i][1]){
                        ans.push_back(vector<int>(B[j]));
                        if(B[j][1] == A[i][1])
                            i++;
                        else
                            A[i][0] = B[j][1];
                        j++;
                    }
                    //A - [0,5]
                    //B - [1,7][5,9]
                    else{
                        ans.push_back(vector<int>({B[j][0], A[i][1]}));
                        if(B[j][0] == A[i][1]){
                            if(B[j][0] == B[j][1])
                                j++;
                            else
                                B[j][0]++;
                        }
                          
                        else
                            B[j][0] = A[i][1]+1;
                        i++;
                    }
                }
            }
            else{ //A[i][0] > B[j][0]
                A.swap(B);
                swap(i,j);
                swap(n,m);
                      
            }
            
        }
        return ans;
    }
};