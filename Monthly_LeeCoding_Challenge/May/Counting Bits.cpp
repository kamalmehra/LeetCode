class Solution {
public:
    vector<int> countBits(int num) {
        // bits in a number = last_bit + the no. div by 2
        vector<int> ans(num+1);
        ans[0] = 0;
        
        for( int i = 1; i < num+1; i++) {
            ans[i] = (i%2) + ans[i/2];
        }
        
        return ans;
    }
};