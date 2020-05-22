class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = 0;
        for(int bit = 31; bit >=0; bit--){
            if((m & (1 << bit)) != (n & (1 << bit)))
                break;
            else
                ans = ans | (m & (1 << bit));
        }
        
        return ans;
    }
};