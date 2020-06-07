class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int> (amount + 1, 0));
        
        for(int i = 0 ; i <= n; i++) {
            for(int j = 0; j <= amount; j++) {
                if(j == 0) dp[i][j] = 1; //make 0 using any no. of coins
                else if(i == 0 or j == 0) continue; //make any no using 0 coins
                
                else if(j - coins[i-1] >= 0) dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]]; 
                
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][amount];
    }
};