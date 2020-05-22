class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        int maxLen = 0;
        
        int k = 0; //subarray sum
        map<int, int> mp; //sum, index
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0) // convert 0 to -1, to apply max subaaray sum = 0
                nums[i] = -1;
            
            sum+=nums[i];
            
            if(sum == k)
                maxLen = max(maxLen, i+1);
            
            if(mp.count(sum-k)!=0)
                maxLen = max(maxLen, i-mp[sum-k]);
            
            if(mp.count(sum) == 0) // if sum already present then lower index will make max subarray
                mp[sum] = i;
        }
        
        return maxLen;
    }
};