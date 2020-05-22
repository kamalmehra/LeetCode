class Solution {
public:

    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        
        while(low<=high){
            mid = low +  (high - low)/2;
            if(low == high) break;
            if(nums[mid-1]!=nums[mid] and nums[mid+1]!=nums[mid])
                break;
            
            
            //4 cases can be present
            if(nums[mid-1]==nums[mid] and mid%2==0){
                high = mid;
                //cout<<"1\n";
            }
            else if (nums[mid-1]==nums[mid] and mid%2!=0){
                low = mid+1;
                //cout<<"2\n";
            }
                
            else if(nums[mid+1]==nums[mid] and mid%2!=0){
                high = mid-1;
                //cout<<"3\n";
            }
            
            else if (nums[mid+1]==nums[mid] and mid%2==0){
                low = mid;
                //cout<<"4\n";
            }
                
        }
        return nums[mid];
    }
    
    //another solution will be to take xor of no but it will be o(n)
};