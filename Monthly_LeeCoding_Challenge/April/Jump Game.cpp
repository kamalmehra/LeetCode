class Solution {
public:
    // we store the min location that we have reached till now from the end of vector. And keep on storing that, if at the end we have 0 in the loc that means we have reached start from end, so return true
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return true;
        int loc = n-1;
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] >= loc-i)
                loc = i;
        }
        
        if (loc == 0)
            return true;
        return false;
    }
};