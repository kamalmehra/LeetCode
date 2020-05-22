class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int nZero = 0;
        for(int i = 0; i<n; i++){
            if(nums[i]==0)
                nZero++;
            else
                nums[i-nZero] = nums[i];
        }
        
        for(int i = n-1; i>(n-nZero-1); i--){
            nums[i] = 0;
        }
    }
};