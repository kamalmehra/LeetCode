class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //getting all local max and min
        int n = prices.size();
        if(n==0 or n==1) return 0;
        
        int count = 0;
        int i = 0; 
        while (i < n - 1) { 
  
            // Find Local Minima 
            // Note that the limit is (n-2) as we are 
            // comparing present element to the next element 
            while ((i < n - 1) && (prices[i + 1] <= prices[i])) 
                i++; 

            // If we reached the end, break 
            // as no further solution possible 
            if (i == n - 1) 
                break; 

            // Store the index of minima 
            int buy = i++; 

            // Find Local Maxima 
            // Note that the limit is (n-1) as we are 
            // comparing to previous element 
            while ((i < n) && (prices[i] >= prices[i - 1])) 
                i++; 

            // Store the index of maxima 
            int sell = i - 1;
            
            count+=(prices[sell] - prices[buy]);
        } 
        
        return count;
    }
};