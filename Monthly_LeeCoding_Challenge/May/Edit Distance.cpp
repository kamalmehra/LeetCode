class Solution {
public:
    int minDistance(string word1, string word2) {
        word2.swap(word1);
        int l1 = word1.length();
        int l2 = word2.length();
        if(l1 == 0 and l2 == 0) return 0;
        if(l1 == 0) return l2;
        if(l2 == 0) return l1;
        
        vector<vector<int>> dp(l1+1,vector<int>(l2+1));
        for(int i = 0; i <= l1; i++){
            for(int j = 0; j <= l2; j++){
                
                if(i == 0) dp[0][j] = j;
                
                else if (j == 0) dp[i][0] = i;
                
                else if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                
                else 
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
            }
        }
        
        for(int i = 0; i <= l1; i++) {
            for(int j = 0; j <= l2; j++){
            }
        }
        
        return dp[l1][l2];
    }
};