class Solution {
public:
	//Can reduce size from O(n) to O(1) by creating a next pointer which will point to the next greater divisible no in set
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return nums;
        //sort in descending order
        sort(nums.begin(), nums.end(), greater<int>());
        
        vector<vector<int>> store(n);
        int MAXLEN = 0;
        int MAXIND = 0;
        
        for(int i = 0; i < n; i++) {
            
            store[i].push_back(nums[i]); // all num are div by themselves
            int j = i - 1;
            int maxSize  = 0;
            int maxIndex = i;
            
            // loop from i to start of array
            while(j >= 0) {
                // if num is div by i and its factor size is the max till now
                if(nums[j] % nums[i] == 0 and store[j].size() > maxSize) {
                    maxSize = store[j].size();
                    maxIndex = j;
                }
                j--;
            }
            
            //if max found, add the vector of j into i
            if(maxIndex != i) {
                store[i].insert(store[i].end(), store[maxIndex].begin(), store[maxIndex].end());
                //if this is the max len found till now
                if(maxSize + 1 > MAXLEN) {
                    MAXLEN = maxSize + 1;
                    MAXIND = i;
                }
            }
        }
        
        return store[MAXIND];
    }
};