class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        if(n == 0) return 0;
        
        int local_max = A[0];
        int local_min = A[0];
        int global_max = A[0];
        int global_min = A[0];
        int A_sum = A[0];
        
        for(int i = 1; i<n; i++){
            //max subarray sum
            local_max = max(A[i], local_max+A[i]);
            global_max = max(local_max, global_max);
            
            //min subarray sum
            local_min = min(A[i], local_min+A[i]);
            global_min = min(local_min, global_min);
            
            //sum of all elements of array
            A_sum+=A[i];
        }
        
        //cout<<global_max<<" "<<global_min<<" "<<A_sum;
        
        if(A_sum == global_min) //all negative elements
            return global_max;

        return max((A_sum-global_min), global_max);
    }
};