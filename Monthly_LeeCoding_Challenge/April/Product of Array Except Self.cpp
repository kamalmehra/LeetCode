class Solution {
public:
    
    //O(n) time and O(1) space
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> start(n);
        vector<int> end(n);
        start[0] = 1;
        end[n-1] = 1;
        
        for(int i = 1; i<n; i++){
            start[i] = start[i-1]*nums[i-1];
            end[n-i-1] = end[n-i]*nums[n-i];
        }
        
        for(int i = 0; i<n; i++){
            nums[i] = start[i]*end[i];
        }
        
        return nums;
        
        
        //O(n) time O(1) space
        // make ans array, then in one for loop calc start, then another for loop for end
    }
};