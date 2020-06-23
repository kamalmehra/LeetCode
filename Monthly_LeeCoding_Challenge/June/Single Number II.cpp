class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //o(nlogn, n space)
//         unordered_map<int,int> s;
        
//         for(auto i: nums)
//             s[i]++;
        
//         for(auto i: s)
//             if (i.second == 1) return i.first;
        
//         return 1;
        
        //bit manipulation II (o(n) and o(1) space)
        int ones = 0;
        int twos = 0;
        
        for(auto i: nums) {
            ones = (ones^i) & (~twos);
            twos = (twos^i) & (~ones);
            
        }
        
        return ones;
    }
};